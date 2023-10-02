//
// Created by Administrator on 2023-10-02.
//

#ifndef QUIET_PRACTICE_TRANSPORT_H
#define QUIET_PRACTICE_TRANSPORT_H

#ifdef USE_WINSOCK
#include <winsock2.h>
#define close closesocket
#define read(s, buf, len) recv(s, buf, len, 0)
#else
#include "quiet-lwip-portaudio.h"
#include "lwip/sockets.h"
#endif

int setup_transport_layer(const char *local_address);

#endif //QUIET_PRACTICE_TRANSPORT_H
