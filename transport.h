//
// Created by Administrator on 2023-10-02.
//

#ifndef QUIET_PRACTICE_TRANSPORT_H
#define QUIET_PRACTICE_TRANSPORT_H

#ifdef USE_WINSOCK
#include <winsock2.h>
#include <mstcpip.h>

#define LWIP_FD_SETSIZE            FD_SETSIZE
#define LWIP_FD_SET                FD_SET
#define LWIP_FD_CLR                FD_CLR
#define LWIP_FD_ISSET              FD_ISSET
#define LWIP_FD_ZERO               FD_ZERO

#define lwip_sockaddr_in           sockaddr_in
#define lwip_sockaddr              sockaddr
#define lwip_fd_set                fd_set

#define lwip_accept(a,b,c)         accept(a,b,c)
#define lwip_bind(a,b,c)           bind(a,b,c)
#define lwip_shutdown(a,b)         shutdown(a,b)
#define lwip_close(s)              closesocket(s)
#define lwip_connect(a,b,c)        connect(a,b,c)
#define lwip_getsockname(a,b,c)    getsockname(a,b,c)
#define lwip_getpeername(a,b,c)    getpeername(a,b,c)
#define lwip_setsockopt(a,b,c,d,e) setsockopt(a,b,c,d,e)
#define lwip_getsockopt(a,b,c,d,e) getsockopt(a,b,c,d,e)
#define lwip_listen(a,b)           listen(a,b)
#define lwip_recv(a,b,c,d)         recv(a,b,c,d)
#define lwip_recvfrom(a,b,c,d,e,f) recvfrom(a,b,c,d,e,f)
#define lwip_send(a,b,c,d)         send(a,b,c,d)
#define lwip_sendto(a,b,c,d,e,f)   sendto(a,b,c,d,e,f)
#define lwip_socket(a,b,c)         socket(a,b,c)
#define lwip_select(a,b,c,d,e)     select(a,b,c,d,e)
#define lwip_ioctl(a,b,c)          ioctlsocket(a,b,c)

#define lwip_read(a,b,c)           recv(a,b,c,0)
#define lwip_write(a,b,c)          send(a,b,c,0)
#define lwip_close(s)              closesocket(s)
#define lwip_fcntl(a,b,c)          fcntl(a,b,c)
#else
#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>
#endif

int setup_transport_layer(const char *local_address);

int set_keepalive(int socket_fd, int idle_sec, int interval_sec, int count);

#endif //QUIET_PRACTICE_TRANSPORT_H
