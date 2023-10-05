//
// Created by Administrator on 2023-10-05.
//

#ifndef QUIET_PRACTICE_UTIL_H
#define QUIET_PRACTICE_UTIL_H

#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

void log_output(FILE *file);
void log_message(const char *message, ...);

#endif //QUIET_PRACTICE_UTIL_H
