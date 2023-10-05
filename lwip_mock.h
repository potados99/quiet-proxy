//
// Created by Administrator on 2023-10-06.
//

#ifndef QUIET_PRACTICE_MOCK_H
#define QUIET_PRACTICE_MOCK_H

#include "opt.h"

// If we use native socket on proxy server for
// listening on incoming connections, we mock
// lwip functions and types with native ones.
#if PROXY_SERVER_LISTENING_INTERFACE == INTERFACE_NATIVE

#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

#define lwip_socket socket
#define lwip_bind bind
#define lwip_listen listen
#define lwip_accept accept
#define lwip_fcntl fcntl
#define lwip_connect connect
#define lwip_select select
#define lwip_shutdown shutdown
#define lwip_recv recv
#define lwip_send send
#define lwip_close close
#define lwip_read read
#define lwip_write write

#define lwip_sockaddr_in sockaddr_in
#define lwip_sockaddr sockaddr

#endif

#endif //QUIET_PRACTICE_MOCK_H
