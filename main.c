//
// Created by Administrator on 2023-10-01.
//

#include <stdio.h>
#include <pthread.h>

#include <winsock2.h>
#include <mstcpip.h>

#include "transport.h"

char *local_address;
int daemon_port;

char *remote_address;
int remote_port;

volatile int active_lwip_socket;

/**
 * 주소와 포트를 받아서 수신용 소켓을 엽니다.
 *
 * @param address
 * @param port
 * @return
 */
int open_receive_socket(const char *address, unsigned short port) {
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

    res = lwip_listen(socket_fd, 1);
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
int open_send_socket(const char *address, unsigned short port) {
    int socket_fd = lwip_socket(AF_INET, SOCK_STREAM, 0);
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
    }

    if (set_keepalive(socket_fd, 1, 1, 3) < 0) {
        printf("[Failed to set keepalive. But keep going]\n");
    }

    return socket_fd;
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
        printf("usage: %s <local address> <local port> <remote address> <remote port>\n", argv[0]);
        return -1;
    }

    local_address = argv[1];
    daemon_port = atoi(argv[2]);

    remote_address = argv[3];
    remote_port = atoi(argv[4]);

    printf("Local: %s:%d\n", local_address, daemon_port);
    printf("Remote: %s:%d\n", remote_address, remote_port);

    return 0;
}

int main(int argc, char **argv) {
    if (handle_args(argc, argv) < 0) {
        return -1;
    }

    if (setup_transport_layer(local_address) < 0) {
        return -2;
    }

    int receive_socket = open_receive_socket(local_address, daemon_port);
    if (receive_socket < 0) {
        return -3;
    }

    fd_set unix_read_fds;
    fd_set unix_ret_fds;

    fd_set lwip_read_fds;
    fd_set lwip_ret_fds;

    FD_ZERO(&unix_read_fds);
    FD_ZERO(&lwip_read_fds);

    FD_SET(STDIN_FILENO, &unix_read_fds);
    FD_SET(receive_socket, &lwip_read_fds);
    if (active_lwip_socket) {
        FD_SET(active_lwip_socket, &lwip_read_fds);
    }

    int lwip_max_fd = max(receive_socket, active_lwip_socket);

    while (1) {
        // if stdin?
        // then send it to active socket

        // if new connection?
        // then make it an active socket

        // if active socket?
        // then read from it

        unix_ret_fds = unix_read_fds;
        lwip_ret_fds = lwip_read_fds;

        if (select(STDIN_FILENO+1, &unix_ret_fds, NULL, NULL, NULL) < 0) {
            perror("[Unix select failed]");
            break;
        }

        if (FD_ISSET(0/*stdin*/, &lwip_ret_fds)) {
            char buf[64];
            scanf("%s", buf);

            if (strcmp(buf, "q") == 0) {
                break;
            }

            if (active_lwip_socket) {
                printf("[Sending %d bytes using existing socket]\n", strlen(buf));
            } else {
                printf("[Sending %d bytes using new socket]\n", strlen(buf));
                active_lwip_socket = open_send_socket(remote_address, remote_port);
            }

            int write_len = lwip_write(active_lwip_socket, buf, strlen(buf));
            if (write_len < 0) {
                printf("[Write failed. Close connection]\n");
                lwip_close(active_lwip_socket);
                active_lwip_socket = 0;
                continue;
            }

            printf("[Wrote %d bytes]\n", write_len);
        }

        if (lwip_select(lwip_max_fd, &lwip_ret_fds, NULL, NULL, NULL) < 0) {
            printf("[Lwip select failed]\n");
            break;
        }

        if (FD_ISSET(receive_socket, &lwip_ret_fds)) {
            struct sockaddr_in receive_from;
            int receive_from_len = sizeof(receive_from);

            int client_socket = lwip_accept(receive_socket, (struct sockaddr *) &receive_from, &receive_from_len);
            if (client_socket < 0) {
                printf("Accept failed: %d\n", client_socket);
            }

            if (set_keepalive(client_socket, 1, 1, 3) < 0) {
                printf("[Failed to set keepalive. But keep going]\n");
            }

            printf("[New connection from: %s:%d]\n", inet_ntoa(receive_from.sin_addr), ntohs(receive_from.sin_port));

            if (active_lwip_socket) {
                FD_CLR(active_lwip_socket, &lwip_read_fds);
            }
            active_lwip_socket = client_socket;
            FD_SET(active_lwip_socket, &lwip_read_fds);
        }

        if (active_lwip_socket && FD_ISSET(active_lwip_socket, &lwip_ret_fds)) {
            char buffer[32];

            int bytes_received = lwip_read(active_lwip_socket, buffer, 32);
            if (bytes_received == 0) {
                printf("[Receive failed. Connection is closed]\n");
                lwip_close(active_lwip_socket);
                active_lwip_socket = 0;
                continue;
            } else if (bytes_received == -1) {
                printf("[Receive failed. Connection is aborted]\n");
                lwip_close(active_lwip_socket);
                active_lwip_socket = 0;
                continue;
            }

            printf("[Received %d bytes]\n", bytes_received);

            buffer[bytes_received] = 0;
            printf("%s\n", buffer);
        }
    }

    return -1;
}