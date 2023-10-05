//
// Created by Administrator on 2023-10-05.
//

#include "socks5.h"

#include "util.h"
#include "socks.h"
#include "relay.h"

#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>

int socks5_auth(int socket_fd, int methods) {
    for (int i = 0; i < methods; i++) {
        char method;
        int read = lwip_read(socket_fd, &method, 1);
        if (read < 1) {
            log_message("socks_auth() less than 1 byte read.");
            return -1;
        }

        if (method == SOCKS_AUTH_NOAUTH) {
            // support only SOCKS_AUTH_NOAUTH
            return 0;
        }
    }

    return -1;
}

int socks5_auth_reply(int socket_fd) {
    int answer[] = {SOCKS_VERSION5, SOCKS_AUTH_NOAUTH};

    int written = lwip_write(socket_fd, answer, ARRAY_SIZE(answer));

    return (written == 2) ? 0 : -1;
}

int socks5_command(int socket_fd, int *command) {
    char cmd[4];

    int read = lwip_read(socket_fd, cmd, ARRAY_SIZE(cmd));
    if (read < 4) {
        log_message("socks5_command() less than 4 bytes read.");
        return -1;
    }

    if (cmd[0] != SOCKS_VERSION5) {
        log_message("socks5_command() invalid version: %d.", cmd[0]);
        return -1;
    }

    if (cmd[1] != SOCKS_CMD_CONNECT) {
        log_message("socks5_command() invalid command: %d.", cmd[1]);
        return -1;
    }

    // cmd[2] is a reserved byte

    if (cmd[3] != SOCKS_ADDR_IPV4 && cmd[3] != SOCKS_ADDR_DOMAINNAME) {
        log_message("socks5_command() invalid address type: %d.", cmd[3]);
        return -1;
    }

    *command = (int) cmd[1];

    return 0;
}

int socks5_read_domain(int socket_fd, char **domain, int *domain_len) {
    int len;
    int read = lwip_read(socket_fd, &len, 1);
    if (read < 1) {
        log_message("socks5_read_domain() less than 1 byte read.");
        return -1;
    }

    char *buf = calloc(len + 1, sizeof(char));

    read = lwip_read(socket_fd, buf, len);
    if (read < len) {
        log_message("socks5_read_domain() less than %d bytes read.", len);
        return -1;
    }

    buf[len] = 0;

    *domain = buf;
    *domain_len = len;

    return 0;
}

int socks5_domain_send_response(int socket_fd, char *domain, int domain_len, unsigned short int port) {
    char response[] = {SOCKS_VERSION5, SOCKS_CONN_SUCCEEDED, 0, SOCKS_ADDR_DOMAINNAME};

    if (lwip_write(socket_fd, response, ARRAY_SIZE(response)) < (int)ARRAY_SIZE(response)) {
        return -1;
    }

    if (lwip_write(socket_fd, &domain_len, sizeof(char)) < (int)sizeof(char)) {
        return -1;
    }

    if (lwip_write(socket_fd, domain, domain_len * sizeof(char)) < domain_len * (int)sizeof(char)) {
        return -1;
    }

    if (lwip_write(socket_fd, &port, sizeof(port)) < (int)sizeof(port)) {
        return -1;
    }

    return 0;
}

int socks5_ip_send_response(int socket_fd, char *ip, unsigned short int port) {
    char response[] = {SOCKS_VERSION5, SOCKS_CONN_SUCCEEDED, 0, SOCKS_ADDR_IPV4};

    if (lwip_write(socket_fd, response, ARRAY_SIZE(response)) < (int)ARRAY_SIZE(response)) {
        return -1;
    }

    if (lwip_write(socket_fd, ip, IPSIZE * sizeof(char)) < IPSIZE * (int)sizeof(char)) {
        return -1;
    }

    if (lwip_write(socket_fd, &port, sizeof(port)) < 2) {
        return -1;
    }

    return 0;
}



