#include "relay.h"

#include "util.h"

static int threads = 0;
static pthread_mutex_t teardown_mutex = PTHREAD_MUTEX_INITIALIZER;

void start_threads(side_t *this_side, side_t *other_side) {
    // We need to heap copy the sides because they must be shared between threads.
    side_t *this_side_copy = malloc(sizeof(side_t));
    memcpy(this_side_copy, this_side, sizeof(side_t));

    side_t *other_side_copy = malloc(sizeof(side_t));
    memcpy(other_side_copy, other_side, sizeof(side_t));

    // These are just a struct to pass the sides to the threads.
    // Note that these also need to be heap allocated:
    // accessing stack memory from another thread is undefined behavior.
    // The threads will free them when they receive them.
    pair_t *from_this_to_other = malloc(sizeof(pair_t));
    from_this_to_other->from = this_side_copy;
    from_this_to_other->to = other_side_copy;

    pair_t *from_other_to_this = malloc(sizeof(pair_t));
    from_other_to_this->from = other_side_copy;
    from_other_to_this->to = this_side_copy;

    // We use two threads per connection.
    // Why? It is because we can't use select() for both lwip and native sockets at the same time.
    // So instead of using select() with two sockets, we use two threads to listen to each of them.
    pthread_t other_facing_thread;
    pthread_create(&other_facing_thread, NULL, relay_loop, (void *) from_this_to_other);

    pthread_t this_facing_thread;
    pthread_create(&this_facing_thread, NULL, relay_loop, (void *) from_other_to_this);
}

void *relay_loop(void *pair) {
    log_message("Running threads: %d", ++threads);

    pair_t sides = *((pair_t *) pair);
    free(pair);

    side_t *from = sides.from;
    side_t *to = sides.to;
    uint8_t buf[1 << 13];

    int ret;
    ssize_t nread;
    ssize_t nwritten;
    fd_set fd_set_one;

    while (1) {
        FD_ZERO(&fd_set_one);
        FD_SET(from->fd, &fd_set_one);

        ret = from->select(from->fd + 1, &fd_set_one, NULL, NULL, NULL);
        if (ret < 0 && errno == EINTR) {
            continue;
        }
        if (!FD_ISSET(from->fd, &fd_set_one)) {
            continue;
        }

        nread = from->read(from->fd, buf, sizeof(buf));
        if (nread == 0) {
            log_info("While reading from %s, got EOF.", from->name);
            teardown(from, to);
            break;
        } else if (nread < 0) {
            log_info("While reading from %s, got error: %s.", from->name, strerror(errno));
            teardown(from, to);

            break;
        }

        nwritten = to->write(to->fd, buf, nread);
        if (nwritten == 0) {
            log_info("While writing to %s, got EOF.", to->name);
            teardown(to, from);
            break;
        } else if (nwritten < 0) {
            log_info("While writing to %s, got error: %s.", to->name, strerror(errno));
            teardown(to, from);
            break;
        }
    }

    log_message("Running threads: %d", --threads);

    return NULL;
}

void teardown(side_t *one, side_t *another) {
    // Only one teardown at a time.
    // There might be a chance that both sides are ready to close at the same time.
    // In that case, we don't want to close both sides twice.
    pthread_mutex_lock(&teardown_mutex);

    // I'm ready.
    one->ready_to_close = 1;

    // If the other side is ready, close both sides.
    if (another->ready_to_close) {
        log_message("Teardown: Both sides are ready to close. Closing.");

        one->close(one->fd);
        another->close(another->fd);

        free(one);
        free(another);
    } else {
        // If the other side is not ready, shutdown the write end.
        // This will cause the other side to get an EOF.
        // This will cause the other side to be ready to close.
        another->shutdown(another->fd, SHUT_WR);
    }

    pthread_mutex_unlock(&teardown_mutex);
}
