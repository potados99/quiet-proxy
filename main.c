//
// Created by Administrator on 2023-10-01.
//

#include <stdio.h>
#include <pthread.h>
#include "transport.h"

char *local_address;
int local_port;

char *remote_address;
int remote_port;

int active_socket;

/**
 * 주소와 포트를 받아서 수신용 소켓을 엽니다.
 *
 * @param address
 * @param port
 * @return
 */
int open_receive_socket(const char *address, unsigned short port) {
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

    res = listen(socket_fd, 1);
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
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
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

    return socket_fd;
}

/**
 * 활성화된 소켓에서 들어온 데이터를 읽습니다.
 * 만약 연결이 끊어지면, active_socket을 0으로 설정합니다.
 *
 * @return
 */
void *handler_loop() {
    while (1) {
        if (!active_socket) {
            continue;
        }

        char buffer[32];

        int bytes_received = read(active_socket, buffer, 32);
        if (bytes_received < 0) {
            printf("[Receive failed. Stop receiving]\n");
            close(active_socket);
            active_socket = 0;
            return NULL;
        }

        printf("[Received %d bytes]\n", bytes_received);

        buffer[bytes_received] = 0;
        printf("%s\n", buffer);
    }
}

/**
 * 새 스레드에서 handler_loop를 실행합니다.
 *
 * @return 새로 생성된 스레드를 반환합니다.
 */
pthread_t start_handler_thread() {
    printf("[Starting handler thread]\n");

    pthread_t thread;
    pthread_create(&thread, NULL, handler_loop, NULL);
    return thread;
}

/**
 * 수신용 소켓을 열고, 새로 들어오는 연결을 감지합니다.
 * 새 연결이 생기면, 새 스레드에서 새 연결을 처리합니다.
 *
 * 만약 이미 활성화된 소켓이 있으면, 새 연결을 무시합니다.
 *
 * @return
 */
void *listen_loop() {
    int receive_socket = open_receive_socket(local_address, local_port);
    if (receive_socket < 0) {
        return NULL;
    }

    printf("[Start listening on receive socket]\n");

    while (1) {
        if (active_socket) {
            continue;
        }

        struct sockaddr_in receive_from;
        int receive_from_len = sizeof(receive_from);

        int client_socket = accept(receive_socket, (struct sockaddr *) &receive_from, &receive_from_len);
        if (client_socket < 0) {
            printf("Accept failed: %d\n", client_socket);
            continue;
        }
        if (active_socket) {
            printf("[Ignore incoming connection due to existing active socket]\n");
            close(client_socket);
            continue;
        }

        printf("[New connection from: %s:%d]\n", inet_ntoa(receive_from.sin_addr), ntohs(receive_from.sin_port));

        active_socket = client_socket;
        start_handler_thread(); // 연결된 소켓에서 듣는 스레드
    }
}

/**
 * 새 스레드에서 listen_loop를 실행합니다.
 *
 * @return 새로 생성된 스레드를 반환합니다.
 */
pthread_t start_listen_thread() {
    printf("[Starting listen thread]\n");

    pthread_t thread;
    pthread_create(&thread, NULL, listen_loop, NULL);
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
        printf("usage: %s <local address> <local port> <remote address> <remote port>\n", argv[0]);
        return -1;
    }

    local_address = argv[1];
    local_port = atoi(argv[2]);

    remote_address = argv[3];
    remote_port = atoi(argv[4]);

    printf("Local: %s:%d\n", local_address, local_port);
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

    start_listen_thread(); // 연결을 기다리는 스레드

    while (1) {
        char buf[64];
        scanf("%s", buf);

        if (active_socket) {
            printf("[Sending %d bytes using existing socket]\n", strlen(buf));
        } else {
            printf("[Sending %d bytes using new socket]\n", strlen(buf));
            active_socket = open_send_socket(remote_address, remote_port);
            start_handler_thread(); // 연결된 소켓에서 듣는 스레드
        }

        send(active_socket, buf, strlen(buf), 0);
    }

    return 0;
}