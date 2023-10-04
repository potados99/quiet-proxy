//
// Created by Administrator on 2023-10-03.
//

/**
 * Daemon의 역할은, 클라이언트의 요청을 받아 다른 호스트에 붙은 클라이언트에게 넘겨주는 것입니다.
 * 클라이언트는 다른 호스트가 존재하는지 모릅니다. 그저 여기 데몬에게 연결할 뿐입니다.
 * 데몬은 그러한 클라이언트를 위하여 다른 호스트(의 데몬)과 연결하여 클라이언트의 요청을 전달합니다.
 *
 * 데몬은 서로간에 연결하기 위해 서버인 동시에 클라이언트로 동작합니다.
 * 먼저 연결 수립을 요청하는 쪽이 클라이언트가 됩니다.
 * 연결은 방향 무관하게, 오직 하나만 존재할 수 있습니다.
*/

#include <stdio.h>
#include <pthread.h>
#include <winsock2.h>

#include "transport.h"
#include "array_list.h"
#include "connection.h"
#include "handshake_lwip.h"
#include "handshake_winsock.h"

char *local_address;
int local_port;

char *remote_address;
int remote_port;

const char *daemon_address = "127.0.0.1";
int daemon_port;

struct array_list winsock_sockets;
struct array_list lwip_sockets;

int winsock_receive_socket(const char *address, unsigned short port) {
    volatile
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Socket failed\n");
        return -1;
    }

    struct sockaddr_in *local_addr = calloc(1, sizeof(struct sockaddr_in));
    local_addr->sin_family = AF_INET;
    local_addr->sin_addr.S_un.S_addr = inet_addr(address);
    local_addr->sin_port = htons(port);

    int res = bind(socket_fd, (struct sockaddr *) local_addr, sizeof(struct sockaddr_in));
    free(local_addr);
    if (res < 0) {
        printf("bind failed\n");
        return -1;
    }

    res = listen(socket_fd, SOMAXCONN);
    if (res < 0) {
        printf("listen failed\n");
        return -1;
    }

    return socket_fd;
}

/**
 * 주소와 포트를 받아서 수신용 소켓을 엽니다.
 *
 * @param address
 * @param port
 * @return
 */
int lwip_receive_socket(const char *address, unsigned short port) {
    int socket_fd = lwip_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Socket failed\n");
        return -1;
    }

    struct lwip_sockaddr_in *local_addr = calloc(1, sizeof(struct lwip_sockaddr_in));
    local_addr->sin_family = AF_INET;
    local_addr->sin_addr.s_addr = inet_addr(address);
    local_addr->sin_port = htons(port);

    int res = lwip_bind(socket_fd, (struct lwip_sockaddr *) local_addr, sizeof(struct lwip_sockaddr_in));
    free(local_addr);
    if (res < 0) {
        printf("bind failed\n");
        return -1;
    }

    res = lwip_listen(socket_fd, SOMAXCONN);
    if (res < 0) {
        printf("listen failed\n");
        return -1;
    }

    return socket_fd;
}

/**
 * 주소와 포트를 받아서 송신용 소켓을 엽니다.
 *
 * @param address
 * @param port
 * @return
 */
int lwip_send_socket(const char *address, unsigned short port) {
    int socket_fd = lwip_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Socket failed\n");
        return -1;
    }

    struct lwip_sockaddr_in remote;
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr(address);
    remote.sin_port = htons(port);

    int res = lwip_connect(socket_fd, (struct sockaddr *) &remote, sizeof(remote));
    if (res < 0) {
        printf("Connect failed\n");
        return -1;
    }

    if (set_keepalive(socket_fd, 1, 1, 3) < 0) {
        printf("[Failed to set keepalive. But keep going]\n");
    }

    return socket_fd;
}

void *winsock_handler() {
    fd_set read_fds;

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int socket;
    int selected;

    int receive_socket = winsock_receive_socket(daemon_address, daemon_port);
    if (receive_socket < 0) {
        printf("Failed to open winsock receive socket.\n");
        return NULL;
    }

    array_list_init(&winsock_sockets);

    while (1) {
        FD_ZERO(&read_fds);

        // the listening socket
        FD_SET(receive_socket, &read_fds);

        // the client sockets
        array_list_foreach(&winsock_sockets, socket) {
            FD_SET(socket, &read_fds);
        }

        selected = select(0/*ignored on windows*/, &read_fds, NULL, NULL, &timeout);
        if (selected == 0) {
            // timed out
            continue;
        }
        if (selected == -1) {
            printf("Winsock select failed\n");
            break;
        }

        // new connection?
        if (FD_ISSET(receive_socket, &read_fds)) {
            struct sockaddr_in receive_from;
            int receive_from_len = sizeof(receive_from);

            volatile/*prevent optimization*/
            int client_socket = accept(receive_socket, (struct sockaddr *) &receive_from, &receive_from_len);
            if (client_socket < 0) {
                printf("Winsock accept failed\n");
                continue;
            }

            printf("New winsock connection from: %s:%d\n", inet_ntoa(receive_from.sin_addr),
                   ntohs(receive_from.sin_port));

            // The new connection will be followed by a single byte, which is the connection id.
            // Read that and store it.
            int connection_id;
            if (winsock_accept_handshake(client_socket, &connection_id) < 0) {
                printf("Winsock handshake failed.\n");
                closesocket(client_socket);
                continue;
            }

            printf("Handshake succeeded. The new winsock connection(socket %d) id is %d.\n", client_socket,
                   connection_id);

            array_list_add(&winsock_sockets, client_socket);
            pair_winsock_socket(client_socket, connection_id);

            int paired_lwip_socket = get_paired_lwip_socket(client_socket);
            if (paired_lwip_socket < 0) {
                printf("Creating new lwip connection for connection id %d.\n", connection_id);

                int lwip_socket = lwip_send_socket(remote_address, remote_port);
                if (lwip_socket < 0) {
                    printf("Failed to open lwip send socket.\n");
                    continue;
                }

                if (lwip_request_handshake(lwip_socket, &connection_id) < 0) {
                    printf("Lwip handshake failed.\n");
                    lwip_close(lwip_socket);
                    continue;
                }

                array_list_add(&lwip_sockets, lwip_socket);
                pair_winsock_socket(client_socket, connection_id);
                pair_lwip_socket(lwip_socket, connection_id);
            } else {
                printf("Lwip connection for this connection id(%d) already exists: %d.\n", connection_id,
                       paired_lwip_socket);
            }
        }

        array_list_foreach(&winsock_sockets, socket) {
            // bytes incoming?
            if (FD_ISSET(socket, &read_fds)) {
                char buffer[1024];
                int read = recv(socket, buffer, sizeof(buffer), 0);
                if (read <= 0) {
                    printf("Winsock connection closed\n");
                    closesocket(socket);
                    array_list_remove(&winsock_sockets, socket);
                    unpair_winsock_socket(socket);
                    continue;
                }

                printf("Winsock read %d bytes\n", read);

                int lwip_socket = get_paired_lwip_socket(socket);
                if (lwip_socket < 0) {
                    printf("Winsock socket is not paired with lwip socket. Ignoring received data.\n");
                    continue;
                }

                int wrote = lwip_write(lwip_socket, buffer, read);
                if (wrote < 0) {
                    printf("Failed to write to paired lwip socket.\n");
                    lwip_close(lwip_socket);
                    array_list_remove(&lwip_sockets, lwip_socket);
                    unpair_lwip_socket(lwip_socket);
                    continue;
                }

                printf("Forwarded %d bytes from winsock to lwip.\n", wrote);
            }
        }
    }
}

pthread_t start_winsock_thread() {
    printf("Starting winsock thread.\n");

    pthread_t thread;
    pthread_create(&thread, NULL, winsock_handler, NULL);

    return thread;
}

void *lwip_handler() {
    lwip_fd_set read_fds;

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int socket;
    int max_fd;
    int selected;

    int receive_socket = lwip_receive_socket(local_address, local_port);
    if (receive_socket < 0) {
        printf("Failed to open lwip receive socket.\n");
        return NULL;
    }

    array_list_init(&lwip_sockets);

    while (1) {
        LWIP_FD_ZERO(&read_fds);

        // the listening socket
        LWIP_FD_SET(receive_socket, &read_fds);
        max_fd = receive_socket;

        // the client sockets
        array_list_foreach(&lwip_sockets, socket) {
            LWIP_FD_SET(socket, &read_fds);

            if (socket > max_fd) {
                max_fd = socket;
            }
        }

        selected = lwip_select(max_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (selected == 0) {
            // timed out
            continue;
        }
        if (selected == -1) {
            printf("Lwip select failed\n");
            break;
        }

        // new connection?
        if (LWIP_FD_ISSET(receive_socket, &read_fds)) {
            struct sockaddr_in receive_from;
            int receive_from_len = sizeof(receive_from);

            volatile/*prevent optimization*/
            int client_socket = lwip_accept(receive_socket, (struct sockaddr *) &receive_from,
                                            &receive_from_len);
            if (client_socket < 0) {
                printf("Lwip accept failed\n");
                continue;
            }
            printf("New lwip connection from: %s:%d.\n", inet_ntoa(receive_from.sin_addr),
                   ntohs(receive_from.sin_port));

            // The new connection will be followed by a single byte, which is the connection id.
            // Read that and store it.
            int connection_id;
            if (lwip_accept_handshake(client_socket, &connection_id) < 0) {
                printf("Lwip handshake failed.\n");
                lwip_close(client_socket);
                continue;
            }

            printf("Handshake succeeded. The new lwip connection id is %d.\n", connection_id);

            if (set_keepalive(client_socket, 1, 1, 3) < 0) {
                printf("[Failed to set keepalive. But keep going]\n");
            }

            array_list_add(&lwip_sockets, client_socket);
            pair_lwip_socket(client_socket, connection_id);
        }

        array_list_foreach(&lwip_sockets, socket) {
            // bytes incoming?
            if (LWIP_FD_ISSET(socket, &read_fds)) {
                char buffer[1024];
                int read = lwip_read(socket, buffer, sizeof(buffer));
                if (read <= 0) {
                    printf("Lwip connection closed.\n");
                    lwip_close(socket);
                    array_list_remove(&lwip_sockets, socket);
                    unpair_lwip_socket(socket);
                    continue;
                }

                printf("Lwip read %d bytes.\n", read);

                int winsock_socket = get_paired_winsock_socket(socket);
                if (winsock_socket < 0) {
                    printf("Lwip socket is not paired with winsock socket. Ignoring received data.\n");
                    continue;
                }

                int wrote = send(winsock_socket, buffer, read, 0);
                if (wrote < 0) {
                    printf("Failed to write to paired winsock socket.\n");
                    closesocket(winsock_socket);
                    array_list_remove(&winsock_sockets, winsock_socket);
                    unpair_winsock_socket(winsock_socket);
                    continue;
                }

                printf("Forwarded %d bytes from lwip to winsock.\n", wrote);
            }
        }
    }
}

pthread_t start_lwip_thread() {
    printf("Starting lwip thread.\n");

    pthread_t thread;
    pthread_create(&thread, NULL, lwip_handler, NULL);

    return thread;
}

/**
 * 프로그램 실행과 함께 들어온 인자들을 처리합니다.
 * 문제가 있었으면 -1을 반환합니다.
 *
 * @param argc
 * @param argv
 * @return 문제 없었으면 0을, 문제가 있었으면 -1을 반환합니다.
 */
int handle_args(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s <local address> <local port> <remote address> <remote port> <daemon port>\n", argv[0]);
        return -1;
    }

    local_address = argv[1];
    local_port = atoi(argv[2]);

    remote_address = argv[3];
    remote_port = atoi(argv[4]);

    daemon_port = atoi(argv[5]);

    printf("Local: %s:%d\n", local_address, local_port);
    printf("Remote: %s:%d\n", remote_address, remote_port);
    printf("Daemon: %s:%d\n", daemon_address, daemon_port);

    return 0;
}

int main(int argc, char **argv) {
    if (handle_args(argc, argv) < 0) {
        return -1;
    }

    if (setup_transport_layer(local_address) < 0) {
        return -2;
    }

    WSADATA WSAData;
    int error = WSAStartup(MAKEWORD(2, 2), &WSAData);
    if (error) {
        printf("Error - Can not load 'winsock.dll' file\n");
        return -1;
    }

    pthread_t winsock_thread = start_winsock_thread();
    pthread_t lwip_thread = start_lwip_thread();

    pthread_join(winsock_thread, NULL);
    pthread_join(lwip_thread, NULL);

    return -1;
}