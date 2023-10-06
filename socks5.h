//
// Created by Administrator on 2023-10-05.
//

#ifndef QUIET_PRACTICE_SOCKS5_H
#define QUIET_PRACTICE_SOCKS5_H

int socks5_auth(int socket_fd, int methods);

int socks5_auth_not_supported(int socket_fd);

int socks5_auth_reply(int socket_fd);

int socks5_command(int socket_fd, int *command);

int socks5_read_domain(int socket_fd, char **domain, int *domain_len);

int socks5_domain_send_response(int socket_fd, char *domain, int domain_len, unsigned short int port);

int socks5_ip_send_response(int socket_fd, char *ip, unsigned short int port);

#endif //QUIET_PRACTICE_SOCKS5_H
