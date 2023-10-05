//
// Created by Administrator on 2023-10-05.
//

#ifndef QUIET_PRACTICE_LWIP_H
#define QUIET_PRACTICE_LWIP_H

#include <stdint.h>

#include "opt.h"

int start_lwip(const uint8_t *mac, uint32_t ipaddr, uint32_t netmask, uint32_t gateway);
int stop_lwip();

#endif //QUIET_PRACTICE_LWIP_H
