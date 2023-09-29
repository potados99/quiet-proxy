#include <stdio.h>
#include "jansson.h"
#include "fec.h"

int main() {
    printf("Hello, World!\n");
    printf("Jansson is %s\n", jansson_version_str());
    printf("libfec is %p\n", create_viterbi27(9));

    return 0;
}
