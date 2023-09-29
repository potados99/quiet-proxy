#include <stdio.h>
#include "jansson.h"
#include "fec.h"
#include "sndfile.h"
#include "portaudio.h"
#include "liquid.h"
#include "quiet.h"

#include "lwip/sockets.h"
#include "quiet-lwip-portaudio.h"

int main() {
    printf("Hello, World!\n");
    printf("Jansson is %s\n", jansson_version_str());
    printf("libfec is %p\n", create_viterbi27(9));
    printf("libsndfile is %s\n", sf_version_string());
    printf("portaudio is %s\n", Pa_GetVersionText());
    printf("libliquid is %s\n", liquid_version);
    printf("libquiet is %d\n", quiet_success);
    printf("quiet-lwip is %d\n", socket(AF_INET, SOCK_STREAM, 0));

    return 0;
}
