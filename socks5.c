//
// Created by Administrator on 2023-10-05.
//

#include "socks5.h"

#include "util.h"
#include "socks.h"
#include "relay.h"

int socks5_auth(int socket_fd, int methods) {
    int supported = -1;

    for (int i = 0; i < methods; i++) {
        char method;
        int n = readn(socket_fd, &method, 1);
        if (n < 1) {
            log_message("socks_auth() less than 1 byte read.");
            return -1;
        }

        if (method == SOCKS_AUTH_NOAUTH) {
            // support only SOCKS_AUTH_NOAUTH
            supported = 0;
        }
    }

    return supported;
}

int socks5_auth_not_supported(int socket_fd) {
    char answer[2] = {SOCKS_VERSION5, SOCKS_AUTH_NOMETHOD};
    if (writen(socket_fd, (void *) answer, ARRAY_SIZE(answer)) != 0) {
        return -1;
    }

    return 0;
}

int socks5_auth_reply(int socket_fd) {
    char answer[] = {SOCKS_VERSION5, SOCKS_AUTH_NOAUTH};
    if (writen(socket_fd, answer, ARRAY_SIZE(answer)) != 0) {
        return -1;
    }

    return 0;
}

int socks5_command(int socket_fd, int *command) {
    char cmd[4];

    int n = readn(socket_fd, cmd, ARRAY_SIZE(cmd));
    if (n < 4) {
        log_message("socks5_command() less than 4 bytes read.");
        return -1;
    }

    log_message("Command %hhX %hhX %hhX %hhX", cmd[0], cmd[1],cmd[2], cmd[3]);

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

    *command = (int) cmd[3];

    return 0;
}

int socks5_read_domain(int socket_fd, char **domain, int *domain_len) {
    int len;
    int n = readn(socket_fd, &len, 1);
    if (n < 1) {
        log_message("socks5_read_domain() less than 1 byte read.");
        return -1;
    }

    char *buf = calloc(len + 1, sizeof(char));

    n = readn(socket_fd, buf, len);
    if (n < len) {
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

    if (writen(socket_fd, response, ARRAY_SIZE(response)) != 0) {
        return -1;
    }

    if (writen(socket_fd, &domain_len, sizeof(char)) != 0) {
        return -1;
    }

    if (writen(socket_fd, domain, domain_len * sizeof(char)) != 0) {
        return -1;
    }

    if (writen(socket_fd, &port, sizeof(port)) != 0) {
        return -1;
    }

    return 0;
}

int socks5_ip_send_response(int socket_fd, char *ip, unsigned short int port) {
    char response[] = {SOCKS_VERSION5, SOCKS_CONN_SUCCEEDED, 0, SOCKS_ADDR_IPV4};

    if (writen(socket_fd, response, ARRAY_SIZE(response)) != 0) {
        return -1;
    }

    if (writen(socket_fd, ip, IPSIZE * sizeof(char)) != 0) {
        return -1;
    }

    if (writen(socket_fd, &port, sizeof(port)) != 0) {
        return -1;
    }

    return 0;
}




