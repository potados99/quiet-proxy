//
// Created by Administrator on 2023-10-05.
//

#include "socks.h"

#include "opt.h"
#include "util.h"
#include "relay.h"

#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#if PROXY_SERVER_LISTENING_INTERFACE == INTERFACE_LWIP
#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>
#elif PROXY_SERVER_LISTENING_INTERFACE == INTERFACE_NATIVE
#include "lwip_mock.h"
#endif

int socks_invitation(int socket_fd, int *version, int *methods) {
    char init[2];

    ssize_t n = readn(socket_fd, init, ARRAY_SIZE(init));
    if (n < 2) {
        log_message("socks_invitation() less than 2 bytes read.");
        return -1;
    }

    if (init[0] != SOCKS_VERSION4 && init[0] != SOCKS_VERSION5) {
        log_message("socks_invitation() invalid version: %d.", init[0]);
        return -1;
    }

    log_message("Initial %hhX %hhX", init[0], init[1]);

    *version = (int) init[0];
    *methods = (int) init[1];

    return 0;
}

int socks_read_ip(int socket_fd, char **ip) {
    char *buf = calloc(IPSIZE, sizeof(char));
    int n = readn(socket_fd, buf, IPSIZE);
    if (n < IPSIZE) {
        log_message("socks_read_ip() less than %d bytes read.", IPSIZE);
        return -1;
    }

    log_message("IP %hhu.%hhu.%hhu.%hhu", buf[0], buf[1], buf[2], buf[3]);

    *ip = buf;

    return 0;
}

int socks_read_port(int socket_fd, unsigned short int *port) {
    unsigned short int p;
    int n = readn(socket_fd, &p, sizeof(unsigned short int));
    if (n < 2) {
        log_message("socks_read_port() less than 2 bytes read.");
        return -1;
    }

    log_message("Port %hu", ntohs(p));

    *port = ntohs(p);

    return 0;

}

static int _connect(int type, void *buf, unsigned short int port) {
    int fd;
    char address[16] = {0,};

    switch (type) {
        case SOCKS_ADDR_IPV4: {
            char *ip = (char *) buf;
            snprintf(address, ARRAY_SIZE(address), "%hhu.%hhu.%hhu.%hhu", ip[0], ip[1], ip[2], ip[3]);

            struct sockaddr_in remote;
            remote.sin_family = AF_INET;
            remote.sin_addr.s_addr = inet_addr(address);
            remote.sin_port = htons(port);

            log_message("Connect to %s:%d", address, port);

            fd = socket(AF_INET, SOCK_STREAM, 0);
            if (fd < 0) {
                log_message("request_connect() Socket failed.");
                return -1;
            }

            int res = connect(fd, (struct sockaddr *) &remote, sizeof(remote));
            if (res < 0) {
                log_message("request_connect() Connect failed.");
                close(fd);
                return -1;
            }

            return fd;
        }

        case SOCKS_ADDR_DOMAINNAME: {
            char portaddr[6];
            struct addrinfo *res = NULL;
            snprintf(portaddr, ARRAY_SIZE(portaddr), "%d", port);

            log_message("getaddrinfo: %s %s", (char *) buf, portaddr);

            struct addrinfo hints;
            memset(&hints, 0, sizeof(hints));
            hints.ai_family = PF_INET;
            hints.ai_flags = AI_PASSIVE;
            hints.ai_socktype = SOCK_STREAM;

            int ret = getaddrinfo((char *) buf, portaddr, &hints, &res);
            if (ret != 0) {
                log_message("request_connect() getaddrinfo failed: %s.", gai_strerror(ret));
                if (res) {
                    freeaddrinfo(res);
                }
                return -1;
            }

            struct addrinfo *r;
            for (r = res; r != NULL; r = r->ai_next) {
                fd = socket(r->ai_family, r->ai_socktype, r->ai_protocol);
                if (fd == -1) {
                    continue;
                }
                ret = connect(fd, r->ai_addr, r->ai_addrlen);
                if (ret == 0) {
                    freeaddrinfo(res);
                    return fd;
                } else {
                    close(fd);
                }
            }

            freeaddrinfo(res);
            return -1;
        }

        default: {
            log_message("request_connect() invalid address type: %d.", type);
            return -1;
        }
    }
}

int request_connect(int type, void *buf, unsigned short int port) {
    int fd = _connect(type, buf, port);
    if (fd < 0) {
        return -1;
    }

    fcntl(fd, F_SETFL, O_NONBLOCK);

    return fd;
}

int readn(int fd, void *buf, int n) {
    int nread;
    int left = n;

    while (left > 0) {
        nread = lwip_read(fd, buf, left);

        if (nread == -1) {
            if (errno == EINTR || errno == EAGAIN) {
                errno = 0; // just ignore the error.
                continue;
            } else {
                return -1;
            }
        } else if (nread == 0) {
            return 0;
        }

        left -= nread;
        buf += nread;
    }

    return n;
}

int readnull(int fd, char *buf, int max) {
    int nread;
    int i = 0;
    char sym = 0;

    while (i < max) {
        nread = lwip_recv(fd, &sym, sizeof(char), 0);

        if (nread <= 0) {
            break;
        } else {
            buf[i] = sym;
            i++;
        }

        if (sym == 0) {
            break;
        }
    }

    return i;
}

int writen(int fd, void *buf, int n) {
    int nwrite;
    int left = n;

    while (left > 0) {
        nwrite = lwip_write(fd, buf, left);

        if (nwrite == -1) {
            if (errno == EINTR || errno == EAGAIN) {
                errno = 0; // just ignore the error.
                continue;
            } else {
                return -1;
            }
        } else if (nwrite == n) {
            return 0;
        }

        left -= nwrite;
        buf += nwrite;
    }

    return 0;
}