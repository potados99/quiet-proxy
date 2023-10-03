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
#include <mstcpip.h>

#include "transport.h"

char *local_address;
int local_port;

char *remote_address;
int remote_port;

const char *daemon_address = "127.0.0.1";
int daemon_port;

volatile int active_unix_socket;
volatile int active_lwip_socket;

int open_unix_receive_socket(const char *address, unsigned short port) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Socket failed\n");
        return -1;
    }

    struct sockaddr_in *local_addr = calloc(1, sizeof(struct sockaddr_in));
    local_addr->sin_family = AF_INET;
    local_addr->sin_addr.s_addr = inet_addr(address);
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
int open_lwip_receive_socket(const char *address, unsigned short port) {
    int socket_fd = lwip_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Socket failed\n");
        return -1;
    }

    struct sockaddr_in *local_addr = calloc(1, sizeof(struct sockaddr_in));
    local_addr->sin_family = AF_INET;
    local_addr->sin_addr.s_addr = inet_addr(address);
    local_addr->sin_port = htons(port);

    int res = lwip_bind(socket_fd, (struct sockaddr *) local_addr, sizeof(struct sockaddr_in));
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
int open_lwip_send_socket(const char *address, unsigned short port) {
    int socket_fd = lwip_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Socket failed\n");
        return -1;
    }

    struct sockaddr_in remote;
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

void *handler() {
    printf("yo!\n");

    fd_set unix_read_fds;
    fd_set lwip_read_fds;

    struct timeval timeout;

    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    while (1) {
        if (!active_unix_socket || !active_lwip_socket) {
            continue;
        }

        FD_ZERO(&unix_read_fds);
        FD_ZERO(&lwip_read_fds);

        FD_SET(active_unix_socket, &unix_read_fds);

        if (select(0, &unix_read_fds, NULL, NULL, &timeout) < 0) {
            printf("Unix select failed\n");
            break;
        }

        if (FD_ISSET(active_unix_socket, &unix_read_fds)) {
            char buffer[32];

            int bytes_received = recv(active_unix_socket, buffer, 32, 0);
            if (bytes_received == 0) {
                printf("Unix receive failed. Connection is closed.\n");
                closesocket(active_unix_socket);
                active_unix_socket = 0;
                continue;
            } else if (bytes_received == -1) {
                printf("Unix receive failed. Connection is aborted.\n");
                closesocket(active_unix_socket);
                active_unix_socket = 0;
                continue;
            }

            printf("Received %d bytes from unix socket. Forward to lwip socket.\n", bytes_received);

            buffer[bytes_received] = 0;

            int wrote = lwip_write(active_lwip_socket, buffer, bytes_received);
            if (wrote < 0) {
                printf("Failed to write to lwip socket.\n");
                break;
            }
        }

        FD_SET(active_lwip_socket, &lwip_read_fds);

        if (lwip_select(active_lwip_socket + 1, &lwip_read_fds, NULL, NULL, &timeout) < 0) {
            printf("Lwip select failed\n");
            break;
        }

        if (FD_ISSET(active_lwip_socket, &lwip_read_fds)) {
            char buffer[32];

            int bytes_received = lwip_read(active_lwip_socket, buffer, 32);
            if (bytes_received == 0) {
                printf("Lwip receive failed. Connection is closed.\n");
                lwip_close(active_lwip_socket);
                active_lwip_socket = 0;
                continue;
            } else if (bytes_received == -1) {
                printf("Lwip receive failed. Connection is aborted.\n");
                lwip_close(active_lwip_socket);
                active_lwip_socket = 0;
                continue;
            }

            printf("Received %d bytes from lwip socket. Forward to unix socket.\n", bytes_received);

            buffer[bytes_received] = 0;

            int wrote = send(active_unix_socket, buffer, bytes_received, 0);
            if (wrote < 0) {
                printf("Failed to write to unix socket.\n");
                break;
            }
        }
    }
}

pthread_t start_handler() {
    printf("Starting handler thread.\n");

    pthread_t thread;
    pthread_create(&thread, NULL, handler, NULL);
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

    int unix_receive_socket = open_unix_receive_socket(daemon_address, daemon_port);
    int lwip_receive_socket = open_lwip_receive_socket(local_address, local_port);

    fd_set unix_read_fds;
    fd_set lwip_read_fds;

    struct timeval timeout;

    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    while (1) {
        FD_ZERO(&unix_read_fds);
        FD_ZERO(&lwip_read_fds);

        if (!active_unix_socket) {
            FD_SET(unix_receive_socket, &unix_read_fds);

            if (select(0, &unix_read_fds, NULL, NULL, &timeout) < 0) {
                printf("Unix select failed\n");
                return -1;
            }

            if (FD_ISSET(unix_receive_socket, &unix_read_fds)) {
                struct sockaddr_in receive_from;
                int receive_from_len = sizeof(receive_from);

                int unix_client_socket = accept(unix_receive_socket, (struct sockaddr *) &receive_from,
                                                &receive_from_len);
                if (unix_client_socket < 0) {
                    printf("Unix accept failed\n");
                    return -1;
                }
                printf("New unix connection from: %s:%d\n", inet_ntoa(receive_from.sin_addr),
                       ntohs(receive_from.sin_port));

                active_unix_socket = unix_client_socket;

                if (active_lwip_socket) {
                    printf("Reuse lwip connection.\n");
                } else {
                    printf("Open new lwip connection.\n");
                    int socket = open_lwip_send_socket(remote_address, remote_port);
                    if (socket < 0) {
                        printf("Failed to open lwip connection.\n");
                        return -1;
                    }

                    int wrote = lwip_write(socket, "hello", 5);
                    if (wrote < 0) {
                        printf("Failed to write handshake to lwip connection.\n");
                        return -1;
                    }

                    active_lwip_socket = socket;

                    printf("Handshake sent. Active lwip socket is %d.\n", active_lwip_socket);
                }

                printf("Start handling.\n");
                start_handler();
            }
        }

        if (!active_lwip_socket) {
            FD_SET(lwip_receive_socket, &lwip_read_fds);

            if (lwip_select(lwip_receive_socket + 1, &lwip_read_fds, NULL, NULL, &timeout) < 0) {
                printf("Lwip select failed\n");
                return -1;
            }

            if (FD_ISSET(lwip_receive_socket, &lwip_read_fds)) {
                struct sockaddr_in receive_from;
                int receive_from_len = sizeof(receive_from);

                int lwip_client_socket = lwip_accept(lwip_receive_socket, (struct sockaddr *) &receive_from,
                                                     &receive_from_len);
                if (lwip_client_socket < 0) {
                    printf("Lwip accept failed\n");
                    return -1;
                }
                printf("New lwip connection from: %s:%d\n", inet_ntoa(receive_from.sin_addr),
                       ntohs(receive_from.sin_port));

                char buf[32];
                int read = lwip_read(lwip_client_socket, buf, 32);
                if (read < 0) {
                    printf("Lwip handshake read failed\n");
                    return -1;
                }
                buf[read] = '\0';

                active_lwip_socket = lwip_client_socket;

                printf("Lwip handshake read %d bytes: %s. Active lwip socket is now %d.\n", read, buf,
                       active_lwip_socket);
            }
        }
    }

    return -1;
}