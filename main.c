#include <stdio.h>
#include "jansson.h"

int main() {
    printf("Hello, World!\n");
    printf("Jansson is %s\n", jansson_version_str());

    return 0;
}
