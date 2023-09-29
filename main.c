#include <stdio.h>
#include "jansson.h"
#include "fec.h"
#include "sndfile.h"

int main() {
    printf("Hello, World!\n");
    printf("Jansson is %s\n", jansson_version_str());
    printf("libfec is %p\n", create_viterbi27(9));
    printf("libsndfile is %s\n", sf_version_string());

    return 0;
}
