//
// Created by Administrator on 2023-10-01.
//

#include <stdio.h>
#include <winsock2.h>
#include <pthread.h>
#include <error.h>

char *local_address;
int local_port;

char *remote_address;
int remote_port;

int active_socket;

int open_receive_socket(const char *address, unsigned short port) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd < 0) {
        printf("socket failed\n");
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

int open_send_socket(const char *address, unsigned short port) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("socket failed\n");
        return -1;
    }

    struct sockaddr_in remote;
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr(address);
    remote.sin_port = htons(port);

    int res = connect(socket_fd, (struct sockaddr *) &remote, sizeof(remote));
    if (res < 0) {
        printf("connect failed\n");
    }

    return socket_fd;
}

void *handler_loop() {
    while (1) {
        if (active_socket <= 0) {
            // puts("No active socket!");
            continue;
        }

        char buffer[32];

        int bytes_received = recv(active_socket, buffer, 32, 0);
        if (bytes_received < 0) {
            printf("recv failed\n");
        }

        printf("%s", buffer);
    }
}

pthread_t start_handler_thread() {
    pthread_t thread;
    pthread_attr_t thread_attr;

    pthread_attr_init(&thread_attr);
    pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE);

    pthread_create(&thread, &thread_attr, handler_loop, NULL);

    pthread_attr_destroy(&thread_attr);
}

void *listen_loop() {
    WSADATA WSAData;
    int error = WSAStartup(MAKEWORD(2, 2), &WSAData);
    if (error)
    {
        printf("Error - Can not load 'winsock.dll' file\n");
        return NULL;
    }

    int receive_socket = open_receive_socket(local_address, local_port);
    if (receive_socket < 0) {
        return NULL;
    }

    while (1) {
        struct sockaddr_in receive_from;
        int receive_from_len = sizeof(receive_from);

        int client_socket = accept(receive_socket, (struct sockaddr *)&receive_from, &receive_from_len);
        if (client_socket < 0) {
            printf("accept failed: %d\n", client_socket);
            continue;
        }
        active_socket = client_socket;

        printf("New connection from: %s:%d\n", inet_ntoa(receive_from.sin_addr), ntohs(receive_from.sin_port));

        start_handler_thread();
    }
}

pthread_t start_listen_thread() {
    pthread_t thread;
    pthread_attr_t thread_attr;

    pthread_attr_init(&thread_attr);
    pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE);

    pthread_create(&thread, &thread_attr, listen_loop, NULL);

    pthread_attr_destroy(&thread_attr);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("usage: %s <local address> <local port> <remote address> <remote port>\n", argv[0]);
        return 1;
    }

    local_address = argv[1];
    local_port = atoi(argv[2]);

    remote_address = argv[3];
    remote_port = atoi(argv[4]);

    printf("Local: %s:%d\n", local_address, local_port);
    printf("Remote: %s:%d\n", remote_address, remote_port);

    start_listen_thread(); // 연결을 기다리는 스레드

    while (1) {
        char buf[64];
        scanf("%s", buf);

        if (active_socket <= 0) {
            puts("Opening new socket!");
            active_socket = open_send_socket(remote_address, remote_port);
            start_handler_thread(); // 연결된 소켓에서 듣는 스레드
        } else {
            puts("Sending using active socket!");
        }

        send(active_socket, buf, strlen(buf), 0);
    }

    return 0;
}