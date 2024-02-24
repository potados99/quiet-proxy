#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <stdatomic.h>

typedef struct {
    const char *name;
    int fd;
    volatile int ready_to_close;

    ssize_t (*read)(int desc, void *buf, size_t nbytes);

    ssize_t (*write)(int desc, const void *buf, size_t nbytes);

    int (*select)(int num_fds, fd_set *read_fds, fd_set *write_fds,
                  fd_set *except_fds, struct timeval *timeout);

    int (*close)(int fd);

    int (*shutdown)(int fd, int how);
} side_t;

typedef struct {
    side_t *from;
    side_t *to;
} pair_t;

void *relay_loop(void *sides);

void start_threads(side_t *this_side, side_t *other_side);

side_t *create_side(const char *name, int fd, ssize_t (*read)(int, void *, size_t),
                    ssize_t (*write)(int, const void *, size_t),
                    int (*select)(int, fd_set *, fd_set *, fd_set *, struct timeval *),
                    int (*close)(int), int (*shutdown)(int, int));