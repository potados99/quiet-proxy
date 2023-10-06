#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>

#include "opt.h"
#include "relay.h"
#include "lwip.h"
#include "util.h"

const char *listening_address = "127.0.0.1";
const int listening_port = PROXY_CLIENT_LISTENING_PORT;
const char *remote_address = PROXY_CLIENT_REMOTE_ADDRESS;
const int remote_port = PROXY_CLIENT_REMOTE_PORT;

const uint8_t *mac = PROXY_CLIENT_LWIP_MAC;
const quiet_lwip_ipv4_addr ipaddr = PROXY_CLIENT_LWIP_ADDRESS_U32;
const quiet_lwip_ipv4_addr netmask = PROXY_CLIENT_LWIP_NETMASK_U32;
const quiet_lwip_ipv4_addr gateway = PROXY_CLIENT_LWIP_GATEWAY_U32;

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
    socklen_t recv_from_len = sizeof(recv_from);
    return accept(socket_fd, (struct sockaddr *) recv_from, &recv_from_len);
}

int app_loop(crossbar *client_crossbar, crossbar *remote_crossbar) {
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

        relay_conn *conn = relay_conn_create(conn_fd, remote_fd, 1 << 13);

        crossbar_add_for_reading(client_crossbar, conn);
        crossbar_add_for_reading(remote_crossbar, conn);
    }
}

int main(int argc, char **argv) {
    signal(SIGPIPE, SIG_IGN);
    log_output(stdout);

    if (start_lwip((uint8_t *) mac, ipaddr, netmask, gateway) < 0) {
        return -1;
    }

    crossbar client_crossbar;
    crossbar remote_crossbar;
    crossbar_init(&client_crossbar);
    crossbar_init(&remote_crossbar);

    relay_t client_relay = {
            .agent = agent_native,
            .other_agent = agent_lwip,
            .incoming = &client_crossbar,
            .outgoing = &remote_crossbar,
            .read = read,
            .write = write,
            .select = select,
            .other_shutdown = lwip_shutdown,
            .get_errno = native_errno,
    };

    relay_t remote_relay = {
            .agent = agent_lwip,
            .other_agent = agent_native,
            .incoming = &remote_crossbar,
            .outgoing = &client_crossbar,
            .read = (ssize_t (*)(int, void *, size_t)) lwip_read,
            .write = (ssize_t (*)(int, const void *, size_t)) lwip_write,
            .select = lwip_select,
            .other_shutdown = shutdown,
            .get_errno = lwip_errno,
    };

    start_relay_thread(&client_relay);
    start_relay_thread(&remote_relay);

    app_loop(&client_crossbar, &remote_crossbar);

    stop_lwip();

    return 0;
}
