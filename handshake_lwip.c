//
// Created by Administrator on 2023-10-04.
//

#include "handshake_lwip.h"

#include <stdio.h>

#include "transport.h"

int lwip_send_initial_handshake(int socket, const int *connection_id) {
    char buf[1];
    buf[0] = (char) *connection_id;

    int written = lwip_write(socket, buf, 1);
    if (written < 0) {
        return -1;
    }

    return 0;
}

int lwip_read_initial_handshake(int socket, int *connection_id) {
    char buf[1];
    int read = lwip_read(socket, buf, 1);
    if (read < 0) {
        return -1;
    }
    buf[read] = '\0';
    printf("handshake: %s\n", buf);

    *connection_id = (int) buf[0];

    return 0;
}

int lwip_send_reply_handshake(int socket, const int *connection_id) {
    char buf[1];
    buf[0] = (char) *connection_id;

    int written = lwip_write(socket, buf, 1);
    if (written < 0) {
        return -1;
    }

    return 0;
}

int lwip_read_reply_handshake(int socket, int *connection_id) {
    char buf[1];
    int read = lwip_read(socket, buf, 1);
    if (read < 0) {
        return -1;
    }
    buf[read] = '\0';

    *connection_id = (int) buf[0];

    return 0;
}

int lwip_request_handshake(int socket, int *connection_id) {
    if (lwip_send_initial_handshake(socket, connection_id) < 0) {
        printf("Lwip lwip_send_initial_handshake failed\n");
        lwip_close(socket);
        return -1;
    }
    if (lwip_read_reply_handshake(socket, connection_id) < 0) {
        printf("Lwip lwip_read_reply_handshake failed\n");
        lwip_close(socket);
        return -1;
    }

    return 0;
}

int lwip_accept_handshake(int socket, int *connection_id) {
    if (lwip_read_initial_handshake(socket, connection_id) < 0) {
        printf("Lwip lwip_read_initial_handshake failed\n");
        lwip_close(socket);
        return -1;
    }
    if (lwip_send_reply_handshake(socket, connection_id) < 0) {
        printf("Lwip lwip_send_reply_handshake failed\n");
        lwip_close(socket);
        return -1;
    }

    return 0;
}
