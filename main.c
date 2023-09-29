#include <stdio.h>
#include "jansson.h"
#include "fec.h"
#include "sndfile.h"
#include "portaudio.h"
#include "liquid.h";

int main() {
    printf("Hello, World!\n");
    printf("Jansson is %s\n", jansson_version_str());
    printf("libfec is %p\n", create_viterbi27(9));
    printf("libsndfile is %s\n", sf_version_string());
    printf("portaudio is %s\n", Pa_GetVersionText());
    printf("libliquid is %s\n", liquid_version);

    return 0;
}
