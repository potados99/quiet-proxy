#include <unistd.h>
#include <signal.h>

#include "quiet-portaudio.h"

#define QUIET_PROFILES_LOCATION "quiet-profiles.json"
#define QUIET_PROFILE "cable-64k"

static quiet_portaudio_decoder *decoder = NULL;
static void sig_handler(int signal) {
    if (decoder) {
        quiet_portaudio_decoder_close(decoder);
    }
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

    /**
     * 위에서 디코더를 만들었습니다.
     * 디코더를 만든 순간부터 Pa는 비동기 입출력을 시작하고,
     * 별도의 새 스레드는 Pa 콜백이 쌓은 샘플들을 디코더에게 넘겨 처리합니다.
     * 디코더는 자신이 처리한 바이트들을 가지고 있을 것입니다.
     * 우리는 메인 스레드에 있으면서 무한 루프 속에서 그 바이트들을 가져오면 됩니다.
     */

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

    return 0;
}
