//
// Created by Administrator on 2023-10-05.
//

#include "socks4.h"

#include "util.h"
#include "socks.h"
#include "relay.h"

int socks4_read_id(int socket_fd, char *buf, int buf_len) {
    readnull(socket_fd, buf, buf_len);

    return 0;
}

int socks4_read_domain(int socket_fd, char *buf, int buf_len) {
    int n = readnull(socket_fd, buf, buf_len);
    if (n < 1) {
        log_message("socks4_read_domain() less than %d byte read.", buf_len);
        return -1;
    }

    return 0;
}

int socks4_is_4a(const char *ip) {
    return (ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] != 0);
}

int socks4_send_response(int fd, int status) {
    char response[8] = {0x00, (char) status, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    if (writen(fd, response, ARRAY_SIZE(response)) < (int)ARRAY_SIZE(response)) {
        return -1;
    }

    return 0;
}
