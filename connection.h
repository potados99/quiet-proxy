//
// Created by Administrator on 2023-10-04.
//

#ifndef QUIET_PRACTICE_CONNECTION_H
#define QUIET_PRACTICE_CONNECTION_H

int get_paired_lwip_socket(int winsock_socket);

int get_paired_winsock_socket(int lwip_socket);

int pair_lwip_socket(int lwip_socket, int connection_id);

int pair_winsock_socket(int winsock_socket, int connection_id);

int get_lwip_connection_id(int lwip_socket);

int get_winsock_connection_id(int winsock_socket);

int unpair_lwip_socket(int lwip_socket);

int unpair_winsock_socket(int winsock_socket);

#endif //QUIET_PRACTICE_CONNECTION_H
