//
// Created by Administrator on 2023-10-05.
//

#include "socks.h"

#include "util.h"
#include "relay.h"

#include <unistd.h>
#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>

int socks_invitation(int socket_fd, int *version, int *methods) {
    char init[2];

    ssize_t read = lwip_read(socket_fd, init, ARRAY_SIZE(init));
    if (read < 2) {
        log_message("socks_invitation() less than 2 bytes read.");
        return -1;
    }

    if (init[0] != SOCKS_VERSION4 && init[0] != SOCKS_VERSION5) {
        log_message("socks_invitation() invalid version: %d.", init[0]);
        return -1;
    }

    *version = (int) init[0];
    *methods = (int) init[1];

    return 0;
}

int socks_read_ip(int socket_fd, char **ip) {
    char *buf = calloc(IPSIZE, sizeof(char));
    if (lwip_read(socket_fd, buf, IPSIZE) < IPSIZE) {
        log_message("socks_read_ip() less than %d bytes read.", IPSIZE);
        return -1;
    }

    log_message("IP %hhu.%hhu.%hhu.%hhu", ip[0], ip[1], ip[2], ip[3]);

    *ip = buf;

    return 0;
}

int socks_read_port(int socket_fd, unsigned short int *port) {
    unsigned short int p;
    int read = lwip_read(socket_fd, &p, sizeof(unsigned short int));
    if (read < 2) {
        log_message("socks_read_port() less than 2 bytes read.");
        return -1;
    }

    log_message("Port %hu", ntohs(p));

    *port = p;

    return 0;

}

int request_connect(int type, void *address, unsigned short int port) {

}
