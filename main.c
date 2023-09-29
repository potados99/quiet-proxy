#include <stdio.h>
#include "jansson.h"
#include "fec.h"
#include "sndfile.h"
#include "portaudio.h"
#include "liquid.h"
#include "quiet.h"
#include "quiet-portaudio.h"


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

    // printf("quiet-lwip is %d\n", socket(AF_INET, SOCK_STREAM, 0));

    

    /* start up PortAudio, which will interface quiet to the soundcard */
    Pa_Initialize();
    
    /* get a profile and set up encoder options, which controls Quiet's modem */
    quiet_encoder_options *encodeOpt = quiet_encoder_profile_filename("C:/Users/Administrator/source/repos/quiet-practice/lib/libquiet/quiet-profiles.json", "audible");

    /* get some default options about device and soundcard setup from PortAudio */
    PaDeviceIndex device = Pa_GetDefaultOutputDevice();

    const PaDeviceInfo *deviceInfo = Pa_GetDeviceInfo(device);
    double sampleRate = deviceInfo->defaultSampleRate;
    PaTime latency = deviceInfo->defaultLowOutputLatency;

    /* select a power of 2 sample buffer size to interface soundcard with
     * this should be between 128 and 16384 */
    const size_t sampleBufferSize = (1 << 14);

    /* start the quiet/PortAudio interface */
    quiet_portaudio_encoder *encoder = quiet_portaudio_encoder_create(encodeOpt, device, latency, sampleRate, sampleBufferSize);

    /* create our message in a uint8_t array */
    const uint8_t msg[] = "Hello, World!";

    /* send the message. this just writes to a send queue
     * behind the scenes, quiet will encode and send as sound samples */
    quiet_portaudio_encoder_send(encoder, msg, sizeof(msg));

    /* stop the quiet/PortAudio interface */
    quiet_portaudio_encoder_close(encoder);
    quiet_portaudio_encoder_destroy(encoder);

    /* free encoder options we created earlier */
    free(encodeOpt);

    /* shut down PortAudio */
    Pa_Terminate();

    return 0;
}
