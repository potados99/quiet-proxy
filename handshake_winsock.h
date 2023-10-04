//
// Created by Administrator on 2023-10-04.
//

#ifndef QUIET_PRACTICE_HANDSHAKE_WINSOCK_H
#define QUIET_PRACTICE_HANDSHAKE_WINSOCK_H

int winsock_send_initial_handshake(int socket, const int *connection_id);

int winsock_read_initial_handshake(int socket, int *connection_id);

int winsock_send_reply_handshake(int socket, const int *connection_id);

int winsock_read_reply_handshake(int socket, int *connection_id);

int winsock_request_handshake(int socket, int *connection_id);

int winsock_accept_handshake(int socket, int *connection_id);

#endif //QUIET_PRACTICE_HANDSHAKE_WINSOCK_H
