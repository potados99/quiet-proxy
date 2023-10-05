#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>

#include "opt.h"
#include "lwip.h"
#include "util.h"
#include "relay.h"
#include "socks.h"
#include "socks4.h"
#include "socks5.h"

#include "lwip_mock.h"

const char *listening_address = PROXY_SERVER_LISTENING_ADDRESS;
const int listening_port = PROXY_SERVER_LISTENING_PORT;

const uint8_t *mac = PROXY_SERVER_LWIP_MAC;
const quiet_lwip_ipv4_addr ipaddr = PROXY_SERVER_LWIP_ADDRESS_U32;
const quiet_lwip_ipv4_addr netmask = PROXY_SERVER_LWIP_NETMASK_U32;
const quiet_lwip_ipv4_addr gateway = PROXY_SERVER_LWIP_GATEWAY_U32;

int open_recv(const char *addr) {
    int socket_fd = lwip_socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        log_message("open_recv() socket failed.");
        return -1;
    }

    struct lwip_sockaddr_in *local_addr = calloc(1, sizeof(struct lwip_sockaddr_in));
    local_addr->sin_family = AF_INET;
    local_addr->sin_addr.s_addr = inet_addr(addr);
    local_addr->sin_port = htons(listening_port);

    int res = lwip_bind(socket_fd, (struct lwip_sockaddr *) local_addr, sizeof(struct lwip_sockaddr_in));
    free(local_addr);

    if (res < 0) {
        log_message("open_recv() bind failed.");
        return -1;
    }

    res = lwip_listen(socket_fd, 1);
    if (res < 0) {
        log_message("open_recv() listen failed.");
        return -1;
    }

    return socket_fd;
}

int recv_connection(int socket_fd, struct lwip_sockaddr_in *recv_from) {
    int recv_from_len = sizeof(*recv_from);

    int conn_fd = lwip_accept(socket_fd, (struct lwip_sockaddr *) recv_from, &recv_from_len);
    if (conn_fd < 0) {
        return -1;
    }

    lwip_fcntl(conn_fd, F_SETFL, O_NONBLOCK);

    return conn_fd;
}

void app_loop(crossbar *client_crossbar, crossbar *remote_crossbar) {
    int recv_socket = open_recv(listening_address);
    if (recv_socket < 0) {
        log_message("app_loop() couldn't open socket for listening.");
        exit(1);
    }

    while (1) {
        int remote_fd = -1;

        struct lwip_sockaddr_in recv_from;
        int conn_fd = recv_connection(recv_socket, &recv_from);
        if (conn_fd < 0) {
            log_message("app_loop() Couldn't accept connection.");
            continue;
        }

        struct in_addr local_domain;
        local_domain.s_addr = recv_from.sin_addr.s_addr;
        log_message("Received connection from %s", inet_ntoa(local_domain));

        int version;
        int methods;
        if (socks_invitation(conn_fd, &version, &methods) < 0) {
            log_message("app_loop() Socks invitation failed.");
            lwip_close(conn_fd);
            continue;
        }

        switch (version) {
            case SOCKS_VERSION5: {
                if (socks5_auth(conn_fd, methods) < 0) {
                    log_message("app_loop() Socks auth failed.");
                    lwip_close(conn_fd);
                    continue;
                }

                if (socks5_auth_reply(conn_fd) < 0) {
                    log_message("app_loop() Socks auth reply failed.");
                    lwip_close(conn_fd);
                    continue;
                }

                int command;
                if (socks5_command(conn_fd, &command) < 0) {
                    log_message("app_loop() Socks command failed.");
                    lwip_close(conn_fd);
                    continue;
                }

                switch (command) {
                    case SOCKS_ADDR_IPV4: {
                        char *ip;
                        if (socks_read_ip(conn_fd, &ip) < 0) {
                            log_message("app_loop() Socks read ip failed.");
                            lwip_close(conn_fd);
                            continue;
                        }

                        unsigned short int port;
                        if (socks_read_port(conn_fd, &port) < 0) {
                            log_message("app_loop() Socks read port failed.");
                            lwip_close(conn_fd);
                            continue;
                        }

                        if ((remote_fd = request_connect(SOCKS_ADDR_IPV4, ip, port)) < 0) {
                            lwip_close(conn_fd);
                            log_message("app_loop() socks request failed.");
                            free(ip);
                            continue;
                        }

                        if (socks5_ip_send_response(conn_fd, ip, port) < 0) {
                            lwip_close(conn_fd);
                            log_message("app_loop() socks request reply failed.");
                            free(ip);
                            continue;
                        }

                        free(ip);
                        break;
                    }

                    case SOCKS_ADDR_DOMAINNAME: {
                        char *domain;
                        int domain_len;
                        if (socks5_read_domain(conn_fd, &domain, &domain_len) < 0) {
                            log_message("app_loop() Socks read domain failed.");
                            lwip_close(conn_fd);
                            continue;
                        }

                        unsigned short int port;
                        if (socks_read_port(conn_fd, &port) < 0) {
                            log_message("app_loop() Socks read port failed.");
                            lwip_close(conn_fd);
                            continue;
                        }

                        if ((remote_fd = request_connect(SOCKS_ADDR_DOMAINNAME, domain, port)) < 0) {
                            lwip_close(conn_fd);
                            log_message("app_loop() socks request failed.");
                            free(domain);
                            continue;
                        }

                        if (socks5_domain_send_response(conn_fd, domain, domain_len, port) < 0) {
                            lwip_close(conn_fd);
                            log_message("app_loop() socks request reply failed.");
                            free(domain);
                            continue;
                        }

                        free(domain);
                        break;
                    }

                    default: {
                        log_message("app_loop() Invalid socks5 command: %d.", command);
                        lwip_close(conn_fd);
                        continue;
                    }
                }

                break;
            }

            case SOCKS_VERSION4: {
                switch (methods) {
                    case 1: {
                        unsigned short int p;
                        if (socks_read_port(conn_fd, &p) < 0) {
                            log_message("app_loop() Socks read port failed.");
                            lwip_close(conn_fd);
                            continue;
                        }

                        char *ip;
                        if (socks_read_ip(conn_fd, &ip) < 0) {
                            log_message("app_loop() Socks read ip failed.");
                            lwip_close(conn_fd);
                            continue;
                        }

                        char ident[255];
                        if (socks4_read_id(conn_fd, ident, sizeof(ident)) < 0) {
                            log_message("app_loop() Socks read ident failed.");
                            lwip_close(conn_fd);
                            continue;
                        }

                        if (socks4_is_4a(ip)) {
                            char domain[255];
                            if (socks4_read_domain(conn_fd, domain, sizeof(domain)) < 0) {
                                log_message("app_loop() Socks read domain failed.");
                                lwip_close(conn_fd);
                                continue;
                            }
                            log_message("Socks4A: ident:%s; domain:%s;", ident, domain);

                            if ((remote_fd = request_connect(SOCKS_ADDR_DOMAINNAME, domain, p)) < 0) {
                                socks4_send_response(conn_fd, 0x5a);
                                lwip_close(conn_fd);
                                log_message("app_loop() socks request failed.");
                                free(ip);
                                continue;
                            }
                        } else {
                            log_message("Socks4: connect by ip & port", ip, p);

                            if ((remote_fd = request_connect(SOCKS_ADDR_IPV4, ip, p)) < 0) {
                                socks4_send_response(conn_fd, 0x5b);
                                lwip_close(conn_fd);
                                log_message("app_loop() socks request failed.");
                                free(ip);
                                continue;
                            }
                        }

                        socks4_send_response(conn_fd, 0x5a);

                        free(ip);
                        break;
                    }

                    default: {
                        log_message("app_loop() Invalid socks4 methods: %d.", methods);
                        lwip_close(conn_fd);
                        continue;
                    }
                }

                break;
            }

            default: {
                log_message("app_loop() Invalid socks version: %d.", version);
                lwip_close(conn_fd);
                continue;
            }
        }

        relay_conn *conn = relay_conn_create(remote_fd, conn_fd, 1 << 13);

        crossbar_add_for_reading(client_crossbar, conn);
        crossbar_add_for_reading(remote_crossbar, conn);
    }
}

int main(int argc, char **argv) {
   // signal(SIGPIPE, SIG_IGN);
    log_output(stdout);

#if PROXY_SERVER_LISTENING_INTERFACE == INTERFACE_LWIP
    if (start_lwip(mac, ipaddr, netmask, gateway) < 0) {
        return -1;
    }
#endif

    crossbar client_crossbar;
    crossbar remote_crossbar;
    crossbar_init(&client_crossbar);
    crossbar_init(&remote_crossbar);

    relay_t client_relay = {
            .agent = agent_lwip,
            .other_agent = agent_native,
            .incoming = &client_crossbar,
            .outgoing = &remote_crossbar,
            .read = lwip_read,
            .write = lwip_write,
            .select = lwip_select,
            .close = lwip_close,
            .other_close = close,
            .other_shutdown = shutdown,
            .get_errno = lwip_errno,
    };

    relay_t remote_relay = {
            .agent = agent_native,
            .other_agent = agent_lwip,
            .incoming = &remote_crossbar,
            .outgoing = &client_crossbar,
            .read = read,
            .write = write,
            .select = select,
            .close = close,
            .other_close = lwip_close,
            .other_shutdown = lwip_shutdown,
            .get_errno = native_errno,
    };

    start_relay_thread(&client_relay);
    start_relay_thread(&remote_relay);

    app_loop(&client_crossbar, &remote_crossbar);

#if PROXY_SERVER_LISTENING_INTERFACE == INTERFACE_LWIP
    stop_lwip();
#endif

    return 0;
}
