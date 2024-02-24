#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

#include "opt.h"
#include "lwip.h"
#include "util.h"
#include "relay.h"

#if PROXY_CLIENT_REMOTE_INTERFACE == INTERFACE_LWIP

#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>

const uint8_t *mac = PROXY_CLIENT_LWIP_MAC;
const quiet_lwip_ipv4_addr ipaddr = PROXY_CLIENT_LWIP_ADDRESS_U32;
const quiet_lwip_ipv4_addr netmask = PROXY_CLIENT_LWIP_NETMASK_U32;
const quiet_lwip_ipv4_addr gateway = PROXY_CLIENT_LWIP_GATEWAY_U32;
#elif PROXY_CLIENT_REMOTE_INTERFACE == INTERFACE_NATIVE
#include "lwip_mock.h"
#endif

const char *listening_address = PROXY_CLIENT_LISTENING_ADDRESS;
int listening_port = PROXY_CLIENT_LISTENING_PORT;

const char *remote_address = PROXY_CLIENT_REMOTE_ADDRESS;
int remote_port = PROXY_CLIENT_REMOTE_PORT;

int open_send(const char *addr, int port) {
    int socket_fd = lwip_socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        log_message("open_send() Socket failed.");
        return -1;
    }

    struct lwip_sockaddr_in remote;
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = inet_addr(addr);
    remote.sin_port = htons(port);

    int res = lwip_connect(socket_fd, (struct lwip_sockaddr *) &remote, sizeof(remote));
    if (res < 0) {
        log_message("open_send() Connect failed.");
        return -1;
    }

    return socket_fd;
}

int open_recv(const char *addr) {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        log_message("open_recv() Socket failed.");
        return -1;
    }

    struct sockaddr_in *local_addr = calloc(1, sizeof(struct sockaddr_in));
    local_addr->sin_family = AF_INET;
    local_addr->sin_addr.s_addr = inet_addr(addr);
    local_addr->sin_port = htons(listening_port);

    int res = bind(socket_fd, (struct sockaddr *) local_addr, sizeof(struct sockaddr_in));
    free(local_addr);

    if (res < 0) {
        log_message("open_recv() Bind failed.");
        return -1;
    }

    res = listen(socket_fd, 1);
    if (res < 0) {
        log_message("open_recv() Listen failed.");
        return -1;
    }

    return socket_fd;
}

int recv_connection(int socket_fd, struct sockaddr_in *recv_from) {
    socklen_t recv_from_len = sizeof(struct sockaddr_in);

    return accept(socket_fd, (struct sockaddr *) recv_from, &recv_from_len);
}

_Noreturn int app_loop() {
    log_info("Listening on %s %s:%d, will forward connection to %s %s:%d",
             "INTERFACE_NATIVE", listening_address, listening_port,
             PROXY_CLIENT_REMOTE_INTERFACE_STR, remote_address, remote_port);

    int recv_socket = open_recv(listening_address);
    if (recv_socket < 0) {
        log_message("app_loop() couldn't open socket for listening.");
        exit(1);
    }

    while (1) {
        struct sockaddr_in recv_from;
        int conn_fd = recv_connection(recv_socket, &recv_from);
        if (conn_fd < 0) {
            log_message("app_loop() Accept failed.");
            continue;
        }

        log_message("Received connection from %s", inet_ntoa(recv_from.sin_addr));

        int remote_fd = open_send(remote_address, remote_port);
        if (remote_fd < 0) {
            close(conn_fd);
            log_message("Remote connect failed.");
            continue;
        }

        log_message("Connected to remote: %s", remote_address);

        side_t this_side = {
                .fd = conn_fd,
                .name = "native side(talks with browser)",
                .read = read,
                .write = write,
                .select = select,
                .close = close,
                .shutdown = shutdown,
                .ready_to_close = 0
        };

        side_t other_side = {
                .fd = remote_fd,
                .name = "lwip side(talks with lwip proxy server on other host)",
                .read = (ssize_t (*)(int, void *, size_t)) lwip_read,
                .write = (ssize_t (*)(int, const void *, size_t)) lwip_write,
                .select = lwip_select,
                .close = lwip_close,
                .shutdown = lwip_shutdown,
                .ready_to_close = 0
        };

        log_message("Starting relay threads with this connection pair.");

        start_threads(&this_side, &other_side);
    }
}

void handle_arguments(int argc, char **argv) {
    if (argc > 1) {
        int listening_portnum = atoi(argv[1]);
        if (listening_portnum > 0 && listening_portnum < 65536) {
            listening_port = listening_portnum;
        }
    }

    if (argc > 2) {
        int remote_portnum = atoi(argv[2]);
        if (remote_portnum > 0 && remote_portnum < 65536) {
            remote_port = remote_portnum;
        }
    }
}

int main(int argc, char **argv) {
    signal(SIGPIPE, SIG_IGN);
    log_output(stdout);

    handle_arguments(argc, argv);

#if PROXY_CLIENT_REMOTE_INTERFACE == INTERFACE_LWIP
    if (start_lwip(mac, ipaddr, netmask, gateway) < 0) {
        return -1;
    }
#endif

    app_loop();

#if PROXY_CLIENT_REMOTE_INTERFACE == INTERFACE_LWIP
    stop_lwip();
#endif

    return 0;
}
