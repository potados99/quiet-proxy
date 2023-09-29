#include <unistd.h>
#include <signal.h>

#include "quiet-portaudio.h"

#define QUIET_PROFILES_LOCATION "C:/Users/Administrator/source/repos/quiet-practice/lib/libquiet/quiet-profiles.json"
#define QUIET_PROFILE "audible-fsk"

static quiet_portaudio_decoder *decoder = NULL;
static void sig_handler(int signal) {
    if (decoder) {
        quiet_portaudio_decoder_close(decoder);
    }
}

void send() {
    printf("Sending...\n");

    quiet_encoder_options *opt = quiet_encoder_profile_filename(QUIET_PROFILES_LOCATION, QUIET_PROFILE);
    if (!opt) {
        printf("failed to read profile %s from %s\n", QUIET_PROFILE, QUIET_PROFILES_LOCATION);
        exit(1);
    }

    PaError err = Pa_Initialize();
    if (err != paNoError) {
        printf("failed to initialize port audio, %s\n", Pa_GetErrorText(err));
        return;
    }

    PaDeviceIndex device = Pa_GetDefaultOutputDevice();
    if (device == paNoDevice) {
        printf("failed to get output device.\n");
        return;
    }

    const PaDeviceInfo *deviceInfo = Pa_GetDeviceInfo(device);
    double sample_rate = deviceInfo->defaultSampleRate;
    PaTime latency = deviceInfo->defaultLowOutputLatency;

    size_t sample_buffer_size = 16384;
    quiet_portaudio_encoder *e = quiet_portaudio_encoder_create(opt, device, latency, sample_rate, sample_buffer_size);

    const uint8_t msg[] = "Hello, World!";
    quiet_portaudio_encoder_send(e, msg, sizeof(msg));

    quiet_portaudio_encoder_close(e);
    quiet_portaudio_encoder_destroy(e);
    free(opt);
    Pa_Terminate();
}

void receive() {
    printf("Receiving...\n");

    quiet_decoder_options *opt = quiet_decoder_profile_filename(QUIET_PROFILES_LOCATION, QUIET_PROFILE);
    if (!opt) {
        printf("failed to read profile %s from %s\n", QUIET_PROFILE, QUIET_PROFILES_LOCATION);
        exit(1);
    }

    signal(SIGINT, sig_handler);
    signal(SIGTERM, sig_handler);

    PaError err = Pa_Initialize();
    if (err != paNoError) {
        printf("failed to initialize port audio, %s\n", Pa_GetErrorText(err));
        return;
    }

    PaDeviceIndex device = Pa_GetDefaultInputDevice();
    if (device == paNoDevice) {
        printf("failed to get input device.\n");
        return;
    }

    const PaDeviceInfo *deviceInfo = Pa_GetDeviceInfo(device);
    double sample_rate = deviceInfo->defaultSampleRate;
    PaTime latency = deviceInfo->defaultLowInputLatency;

    decoder = quiet_portaudio_decoder_create(opt, device, latency, sample_rate);
    quiet_portaudio_decoder_set_blocking(decoder, 0, 0);

    size_t write_buffer_size = 16384;
    uint8_t *write_buffer = malloc(write_buffer_size*sizeof(uint8_t));

    while (true) {
        ssize_t read = quiet_portaudio_decoder_recv(decoder, write_buffer, write_buffer_size);
        if (read <= 0) {
            break;
        }

        printf("%s", write_buffer);
    }

    free(write_buffer);
    quiet_portaudio_decoder_destroy(decoder);
}

int main() {
    receive();
    //send();

    return 0;
}
