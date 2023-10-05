//
// Created by Administrator on 2023-10-05.
//

#ifndef QUIET_PRACTICE_SOCKS4_H
#define QUIET_PRACTICE_SOCKS4_H

int socks4_read_id(int socket_fd, char *buf, int buf_len);

int socks4_read_domain(int socket_fd, char *buf, int buf_len);

int socks4_is_4a(const char *ip);

int socks4_send_response(int fd, int status);

#endif //QUIET_PRACTICE_SOCKS4_H
