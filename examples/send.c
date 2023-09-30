#include <unistd.h>
#include <signal.h>

#include "quiet-portaudio.h"

#define QUIET_PROFILES_LOCATION "quiet-profiles.json"
#define QUIET_PROFILE "cable-64k"

void send(const char *payload) {
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

    quiet_portaudio_encoder_send(e, payload, strlen(payload));

    quiet_portaudio_encoder_close(e);
    quiet_portaudio_encoder_destroy(e);
    free(opt);
    Pa_Terminate();
}

int main(int argc, char **argv) {
    send(argv[1]);

    return 0;
}
