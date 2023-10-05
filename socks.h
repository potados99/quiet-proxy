//
// Created by Administrator on 2023-10-05.
//

#ifndef QUIET_PRACTICE_SOCKS_H
#define QUIET_PRACTICE_SOCKS_H

#define IPSIZE 4

enum socks_version {
    SOCKS_VERSION4 = 4,
    SOCKS_VERSION5 = 5
};

enum socks_auth {
    SOCKS_AUTH_NOAUTH = 0
};

enum socks_command {
    SOCKS_CMD_CONNECT = 1
};

enum socks_address {
    SOCKS_ADDR_IPV4 = 1,
    SOCKS_ADDR_DOMAINNAME = 3
};

enum socks_response {
    SOCKS_CONN_SUCCEEDED = 0,
    SOCKS_CONN_FAILED = 1
};

int socks_invitation(int socket_fd, int *version, int *methods);

int socks_read_ip(int socket_fd, char **ip);

int socks_read_port(int socket_fd, unsigned short int *port);

int request_connect(int type, void *buf, unsigned short int port);

int readn(int fd, void *buf, int n);

int readnull(int fd, char *buf, int size);

int writen(int fd, void *buf, int n);

#endif //QUIET_PRACTICE_SOCKS_H
