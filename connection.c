//
// Created by Administrator on 2023-10-04.
//

#include "connection.h"

#define CHAR_MAX 255

int lwip_connections[CHAR_MAX];
int winsock_connections[CHAR_MAX];

int get_paired_lwip_socket(int winsock_socket) {
    int connection_id = get_winsock_connection_id(winsock_socket);
    int lwip_socket = lwip_connections[connection_id];

    if (lwip_socket == 0) {
        return -1;
    }

    return lwip_socket;
}

int get_paired_winsock_socket(int lwip_socket) {
    int connection_id = get_lwip_connection_id(lwip_socket);
    int winsock_socket = winsock_connections[connection_id];

    if (winsock_socket == 0) {
        return -1;
    }

    return winsock_socket;
}

int pair_lwip_socket(int lwip_socket, int connection_id) {
    lwip_connections[connection_id] = lwip_socket;
}

int pair_winsock_socket(int winsock_socket, int connection_id) {
    winsock_connections[connection_id] = winsock_socket;
}

int get_lwip_connection_id(int lwip_socket) {
    for (int i = 0; i < CHAR_MAX; i++) {
        if (lwip_connections[i] == lwip_socket) {
            return i;
        }
    }

    return -1;
}

int get_winsock_connection_id(int winsock_socket) {
    for (int i = 0; i < CHAR_MAX; i++) {
        if (winsock_connections[i] == winsock_socket) {
            return i;
        }
    }

    return -1;
}

int unpair_lwip_socket(int lwip_socket) {
    int connection_id = get_lwip_connection_id(lwip_socket);
    if (connection_id < 0) {
        return -1;
    }

    lwip_connections[connection_id] = 0;

    return 0;
}

int unpair_winsock_socket(int winsock_socket) {
    int connection_id = get_winsock_connection_id(winsock_socket);
    if (connection_id < 0) {
        return -1;
    }

    winsock_connections[connection_id] = 0;

    return 0;
}
