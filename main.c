//
// Created by Administrator on 2023-10-01.
//

#include <stdio.h>
#include <pthread.h>
#include "lwip/sockets.h"

int main() {
    lwip_socket(AF_INET, SOCK_STREAM, 0);
    pthread_join(0, 0);
    printf("Hello, World!\n");

    return 0;
}