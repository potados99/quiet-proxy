//
// Created by Administrator on 2023-10-04.
//

#include "handshake_winsock.h"

#include <stdio.h>

#include <winsock2.h>
#include <mstcpip.h>

int winsock_send_initial_handshake(int socket, const int *connection_id) {
    char buf[1];
    buf[0] = (char) *connection_id;

    int written = send(socket, buf, 1, 0);
    if (written < 0) {
        return -1;
    }

    return 0;
}

int winsock_read_initial_handshake(int socket, int *connection_id) {
    char buf[1];
    int read = recv(socket, buf, 1, 0);
    if (read < 0) {
        return -1;
    }
    buf[read] = '\0';
    printf("handshake: %s\n", buf);

    *connection_id = (int) buf[0];

    return 0;
}

int winsock_send_reply_handshake(int socket, const int *connection_id) {
    char buf[1];
    buf[0] = (char) *connection_id;

    int written = send(socket, buf, 1, 0);
    if (written < 0) {
        return -1;
    }

    return 0;
}

int winsock_read_reply_handshake(int socket, int *connection_id) {
    char buf[1];
    int read = recv(socket, buf, 1, 0);
    if (read < 0) {
        return -1;
    }
    buf[read] = '\0';

    *connection_id = (int) buf[0];

    return 0;
}

int winsock_request_handshake(int socket, int *connection_id) {
    if (winsock_send_initial_handshake(socket, connection_id) < 0) {
        printf("Winsock winsock_send_initial_handshake failed\n");
        closesocket(socket);
        return -1;
    }
    if (winsock_read_reply_handshake(socket, connection_id) < 0) {
        printf("Winsock winsock_read_reply_handshake failed\n");
        closesocket(socket);
        return -1;
    }

    return 0;
}

int winsock_accept_handshake(int socket, int *connection_id) {
    if (winsock_read_initial_handshake(socket, connection_id) < 0) {
        printf("Winsock winsock_read_initial_handshake failed\n");
        closesocket(socket);
        return -1;
    }
    if (winsock_send_reply_handshake(socket, connection_id) < 0) {
        printf("Winsock winsock_send_reply_handshake failed\n");
        closesocket(socket);
        return -1;
    }

    return 0;
}
