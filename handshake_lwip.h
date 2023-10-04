//
// Created by Administrator on 2023-10-04.
//

#ifndef QUIET_PRACTICE_HANDSHAKE_LWIP_H
#define QUIET_PRACTICE_HANDSHAKE_LWIP_H

int lwip_send_initial_handshake(int socket, const int *connection_id);

int lwip_read_initial_handshake(int socket, int *connection_id);

int lwip_send_reply_handshake(int socket, const int *connection_id);

int lwip_read_reply_handshake(int socket, int *connection_id);

int lwip_request_handshake(int socket, int *connection_id);

int lwip_accept_handshake(int socket, int *connection_id);

#endif //QUIET_PRACTICE_HANDSHAKE_LWIP_H
