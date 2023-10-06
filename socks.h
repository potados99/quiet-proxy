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
    SOCKS_AUTH_NOAUTH = 0,
    SOCKS_AUTH_NOMETHOD = 255
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

/**
 * Read n bytes from fd and put them into buf.
 *
 * This function consists of subsequent read() calls.
 * Calls will be repeated until n bytes are read or an error occurs.
 * Note: EINTER and EAGAIN are not considered as errors. They will be ignored.
 *
 * It will not return on partial reads. It waits until n bytes are read, and then this function returns.
 *
 * It is convenient to use this function when you want to grab n bytes without regards to partial reads.
 *
 * @param fd file descriptor of socket from where to read.
 * @param buf a buffer where the bytes read will be stored.
 * @param n read how many?
 * @return n if success, 0 if connection closed, -1 if error.
 */
int readn(int fd, void *buf, int n);

/**
 * Read maximum size bytes from fd until null character comes, and put them into buf.
 *
 * This function consists of subsequent read() calls.
 * Calls will be repeated until one of the following conditions occurs:
 * - null character comes
 * - size bytes are read
 * - an error occurs(including EINTER and EAGAIN).
 *
 * Any of the above conditions will immediately stop the read loop and make it return the number of bytes read so far.
 * Note that the null character *is* included in the bytes count and the buffer.
 *
 * Beware that this functions lacks a error check functionality. :-)
 *
 * It is convenient to use this function, because it is good at reading a null terminated strings.
 *
 * @param fd file descriptor of socket from where to read.
 * @param buf a buffer where the bytes read will be stored.
 * @param max maximum size to read.
 * @return number of bytes read so far.
 */
int readnull(int fd, char *buf, int max);

/**
 * Write n bytes from buf into fd.
 *
 * This function consists of subsequent write() calls.
 * Calls will be repeated until n bytes are written or an error occurs.
 * Note: EINTER and EAGAIN are not considered as errors. They will be ignored.
 *
 * It will not return on partial writes. It waits until n bytes are written, and then this function returns.
 *
 * It is convenient to use this function when you want to put n bytes without regards to partial writes.
 *
 * @param fd file descriptor of socket to where to write.
 * @param buf the source buffer
 * @param n write how many?
 * @return 0 if success, -1 if error.
 */
int writen(int fd, void *buf, int n);

#endif //QUIET_PRACTICE_SOCKS_H
