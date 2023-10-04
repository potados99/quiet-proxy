//
// Created by Administrator on 2023-10-03.
//

#include <stdio.h>
#include <winsock2.h>
#include <mstcpip.h>
#include <pthread.h>

#include "handshake_winsock.h"

char *daemon_address;
int daemon_port;

volatile int active_socket;

int set_keepalive(int socket_fd, int idle, int interval, int count) {
    // count는 10회로 고정입니다. 딱히 바꾸는 방법이 없는 것 같습니다...

    struct tcp_keepalive alive;

    alive.onoff = TRUE;
    alive.keepalivetime = idle * 1000;
    alive.keepaliveinterval = interval * 1000;

    DWORD dwBytesRet = 0;

    if (WSAIoctl(socket_fd, SIO_KEEPALIVE_VALS, &alive, sizeof(alive),
                 NULL, 0, &dwBytesRet, NULL, NULL) == SOCKET_ERROR) {
        printf("WSAIotcl(SIO_KEEPALIVE_VALS) failed; %d\n",
               WSAGetLastError());
        return -1;
    }

    return 0;
}

/**
 * 주소와 포트를 받아서 송신용 소켓을 엽니다.
 *
 * @param address
 * @param port
 * @return
 */
int open_send_socket(const char *address, unsigned short port) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("Socket failed\n");
        return -1;
    }

    struct sockaddr_in remote;
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr(address);
    remote.sin_port = htons(port);

    int res = connect(socket_fd, (struct sockaddr *) &remote, sizeof(remote));
    if (res < 0) {
        printf("Connect failed\n");
    }

    if (set_keepalive(socket_fd, 1, 1, 3) < 0) {
        printf("[Failed to set keepalive. But keep going]\n");
    }

    return socket_fd;
}

void *handler() {
    while (1) {
        if (!active_socket) {
            continue;
        }

        char buffer[32];

        int bytes_received = recv(active_socket, buffer, 32, 0);
        if (bytes_received == 0) {
            printf("Receive failed. Connection is closed.\n");
            closesocket(active_socket);
            active_socket = 0;
            continue;
        } else if (bytes_received == -1) {
            printf("Receive failed. Connection is aborted.\n");
            closesocket(active_socket);
            active_socket = 0;
            continue;
        }

        printf("Received %d bytes.\n", bytes_received);

        buffer[bytes_received] = 0;
        printf("[%s]\n", buffer);
    }
}

pthread_t start_handler() {
    printf("[Starting handler thread]\n");

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
        printf("usage: %s <daemon address> <daemon port>\n", argv[0]);
        return -1;
    }

    daemon_address = argv[1];
    daemon_port = atoi(argv[2]);

    printf("Daemon: %s:%d\n", daemon_address, daemon_port);

    return 0;
}

int main(int argc, char **argv) {
    if (handle_args(argc, argv) < 0) {
        return -1;
    }

    WSADATA WSAData;
    int error = WSAStartup(MAKEWORD(2, 2), &WSAData);
    if (error) {
        printf("Error - Can not load 'winsock.dll' file\n");
        return -1;
    }

    printf("Hi. Type anything to start.\n");

    while (1) {
        char buf[64];
        scanf("%s", buf);

        if (strcmp(buf, "q") == 0) {
            break;
        }

        if (active_socket) {
            printf("Sending %d bytes using existing socket.\n", strlen(buf));
        } else {
            printf("Sending %d bytes using new socket.\n", strlen(buf));
            active_socket = open_send_socket(daemon_address, daemon_port);
            if (active_socket < 0) {
                printf("Failed to open socket\n");
                closesocket(active_socket);
                active_socket = 0;
                continue;
            }

            int connection_id = (int)'a'; // TODO hardcoded...
            if (winsock_request_handshake(active_socket, &connection_id) < 0) {
                printf("Handshake failed.\n");
                closesocket(active_socket);
                active_socket = 0;
                continue;
            }

            start_handler();
        }

        int write_len = send(active_socket, buf, strlen(buf), 0);
        if (write_len < 0) {
            printf("Write failed. Close connection\n");
            closesocket(active_socket);
            active_socket = 0;
            continue;
        }

        printf("[Wrote %d bytes]\n", write_len);
    }
}