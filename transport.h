//
// Created by Administrator on 2023-10-02.
//

#ifndef QUIET_PRACTICE_TRANSPORT_H
#define QUIET_PRACTICE_TRANSPORT_H

#ifdef USE_WINSOCK
#include <winsock2.h>
#include <mstcpip.h>
#define close closesocket
#define read(s, buf, len) recv(s, buf, len, 0)
#define write(s, buf, len) send(s, buf, len, 0)
#else
#include "quiet-lwip-portaudio.h"
#include "lwip/sockets.h"
#endif

int setup_transport_layer(const char *local_address);

int set_keepalive(int socket_fd, int idle_sec, int interval_sec, int count);

#endif //QUIET_PRACTICE_TRANSPORT_H
