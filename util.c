//
// Created by Administrator on 2023-10-05.
//

#include "util.h"

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

FILE *log_file;
pthread_mutex_t lock;

void log_output(FILE *file) {
    log_file = file;
}

void log_message(const char *message, ...) {
    char vbuffer[255];
    va_list args;
    va_start(args, message);
    vsnprintf(vbuffer, ARRAY_SIZE(vbuffer), message, args);
    va_end(args);

    time_t now;
    time(&now);
    char *date = ctime(&now);
    date[strlen(date) - 1] = '\0';

    pthread_t self = pthread_self();

    if (errno != 0) {
        pthread_mutex_lock(&lock);
        fprintf(log_file, "[%s][%lu] Critical: %s - %s\n", date, self,
                vbuffer, strerror(errno));
        errno = 0;
        pthread_mutex_unlock(&lock);
    } else {
        fprintf(log_file, "[%s][%lu] Info: %s\n", date, self, vbuffer);
    }
    fflush(log_file);
}
