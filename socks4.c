//
// Created by Administrator on 2023-10-05.
//

#include "socks4.h"

#include "util.h"
#include "relay.h"

#include <quiet-lwip/lwip-socket.h>

int socks4_read_nstring(int fd, char *buf, int size) {
    char sym = 0;
    int nread = 0;
    int i = 0;

    while (i < size) {
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

int socks4_read_id(int socket_fd, char *buf, int buf_len) {
    socks4_read_nstring(socket_fd, buf, sizeof(buf_len));

    return 0;
}

int socks4_read_domain(int socket_fd, char *buf, int buf_len) {
    int read = socks4_read_nstring(socket_fd, buf, sizeof(buf_len));
    if (read < 1) {
        log_message("socks4_read_domain() less than 1 byte read.");
        return -1;
    }

    return 0;
}

int socks4_is_4a(char *ip) {
    return (ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] != 0);
}

int socks4_send_response(int fd, int status) {
    char response[8] = {0x00, (char) status, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    if (lwip_write(fd, response, ARRAY_SIZE(response)) < (int)ARRAY_SIZE(response)) {
        return -1;
    }

    return 0;
}
