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

int set_keepalive(int socket_fd, int idle, int interval, int count) {
    // count는 10회로 고정입니다. 딱히 바꾸는 방법이 없는 것 같습니다...

    struct tcp_keepalive alive;

    alive.onoff = TRUE;
    alive.keepalivetime = idle * 1000;
    alive.keepaliveinterval = interval * 1000;

    DWORD dwBytesRet = 0;

    if (WSAIoctl(socket_fd, SIO_KEEPALIVE_VALS, &alive, sizeof(alive),
            NULL, 0, &dwBytesRet, NULL, NULL) == SOCKET_ERROR)
    {
        printf("WSAIotcl(SIO_KEEPALIVE_VALS) failed; %d\n",
               WSAGetLastError());
        return -1;
    }

    return 0;
}