//
// Created by Administrator on 2023-10-02.
//

#include "transport.h"

#include <stdio.h>

int setup_transport_layer(const char *local_address) {
    WSADATA WSAData;
    int error = WSAStartup(MAKEWORD(2, 2), &WSAData);
    if (error) {
        printf("Error - Can not load 'winsock.dll' file\n");
        return -1;
    }
}