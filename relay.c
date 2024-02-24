#include "relay.h"

#include "util.h"

void *relay(void *pair) {
    pair_t *sides = (pair_t *) pair;
    side_t from = sides->from;
    side_t to = sides->to;
    uint8_t buf[1 << 13];

    int ret;
    ssize_t nread;
    ssize_t nwritten;
    fd_set fd_set_one;

    log_message("Relay thread started.");

    while (1) {
        FD_ZERO(&fd_set_one);
        FD_SET(from.fd, &fd_set_one);

        ret = from.select(from.fd + 1, &fd_set_one, NULL, NULL, NULL);
        if (ret < 0 && errno == EINTR) {
            continue;
        }
        if (!FD_ISSET(from.fd, &fd_set_one)) {
            continue;
        }

        log_info("Will read....");

        nread = from.read(from.fd, buf, sizeof(buf));
        if (nread == 0) {
            // EOF
            log_info("Got EOF on read");
            from.close(from.fd);
            break;
        } else if (nread < 0) {
            // Error
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                log_info("haha");
                continue;
            }
            from.close(from.fd);
            log_info("Got error on read: %s", strerror(errno));
            break;
        }

        log_info("Successfully read %d bytes", nread);

        log_info("Will write....");

        nwritten = to.write(to.fd, buf, nread);
        if (nwritten == 0) {
            // EOF
            log_info("Got EOF on write");
            to.close(to.fd);
            break;
        } else if (nwritten < 0) {
            // Error
            log_info("Got error on write");
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                log_info("haha");
                continue;
            }
            to.close(to.fd);
            break;
        }

        log_info("Successfully wrote %d bytes", nwritten);
    }

    log_info("Relay thread exiting.");


    return NULL;
}

void start_threads(side_t *this_side, side_t *other_side) {
    pair_t from_this_to_other = {
            .from = *this_side,
            .to = *other_side
    };

    pair_t from_other_to_this = {
            .from = *other_side,
            .to = *this_side
    };

    pthread_t other_facing_thread;
    pthread_create(&other_facing_thread, NULL, relay, (void *) &from_this_to_other);

    pthread_t this_facing_thread;
    pthread_create(&this_facing_thread, NULL, relay, (void *) &from_other_to_this);
}
