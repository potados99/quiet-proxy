#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#include "getopt.h"

char *optarg;
int optind = 1;
int optopt = 0;
int opterr = 0;

static int argvind = 1;

int getopt(int argc, char *const argv[], const char *optstring) {
    if (optind == 0) {
        // reset
        optind = 1;
        optopt = 0;
        opterr = 0;
        argvind = 1;
    }

    if (optind >= argc) {
        return -1;
    }

    if (!argv) {
        return -1;
    }

    if (!argv[optind]) {
        return -1;
    }

    size_t arglen = strlen(argv[optind]);

    if (arglen < 2) {
        return -1;
    }

    if (argv[optind][0] != '-') {
        return -1;
    }

    if (arglen == 2 && argv[optind][1] == '-') {
        optind++;
        return -1;
    }

    if (argvind >= arglen) {
        return -1;
    }

    char arg = argv[optind][argvind];

    char *pos = strchr(optstring, arg);
    if (!pos) {
        optopt = arg;
        return '?';
    }

    size_t optstring_len = strlen(optstring);
    ptrdiff_t optstringind = pos - optstring;
    ptrdiff_t nextoptind = optstringind + 1;
    bool has_arg = false;
    bool last_opt = (argvind + 1) == arglen;

    if (nextoptind < optstring_len) {
        has_arg = optstring[nextoptind] == ':';
    }

    if (has_arg && last_opt && (optind + 1) >= argc) {
        optopt = arg;
        return ':';
    }

    if (has_arg) {
        if (last_opt) {
            optarg = argv[optind + 1];
            optind += 2;
        } else {
            optarg = argv[optind] + argvind + 1;
            optind += 1;
        }
        argvind = 1;
        return arg;
    }

    optarg = NULL;
    optopt = 0;

    if (last_opt) {
        optind += 1;
        argvind = 1;
    } else {
        argvind += 1;
    }

    return arg;
}
