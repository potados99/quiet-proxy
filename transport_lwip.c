//
// Created by Administrator on 2023-10-02.
//

#include "transport.h"

#define QUIET_PROFILES_LOCATION "quiet-profiles.json"
#define QUIET_PROFILE "cable-64k"

/**
 * Convert human readable IPv4 address to UINT32
 * @param pIpAddr       Input C string e.g. "192.168.0.1"
 * return 1 on success, else 0
 */
uint32_t inet_pton(const char *pIpAddr) {
    unsigned int byte3;
    unsigned int byte2;
    unsigned int byte1;
    unsigned int byte0;
    char dummyString[2];

    /* The dummy string with specifier %1s searches for a non-whitespace char
     * after the last number. If it is found, the result of sscanf will be 5
     * instead of 4, indicating an erroneous format of the ip-address.
     */
    if (sscanf(pIpAddr, "%u.%u.%u.%u%1s",
               &byte3, &byte2, &byte1, &byte0, dummyString) == 4) {
        if ((byte3 < 256)
            && (byte2 < 256)
            && (byte1 < 256)
            && (byte0 < 256)
                ) {
            return (byte3 << 24)
                   + (byte2 << 16)
                   + (byte1 << 8)
                   + byte0;
        }
    }

    return 0;
}

/**
 * Generate a random byte stream of length num_bytes
 * @param num_bytes
 * @return
 */
unsigned char *gen_rdm_bytestream(size_t num_bytes) {
    unsigned char *stream = malloc(num_bytes);
    size_t i;

    for (i = 0; i < num_bytes; i++) {
        stream[i] = rand();
    }

    return stream;
}

int setup_transport_layer(const char *local_address) {
    srand((unsigned int) time(NULL));

    PaError err = Pa_Initialize();
    if (err != paNoError) {
        printf("failed to initialize port audio, %s\n", Pa_GetErrorText(err));
        return -1;
    }

    quiet_lwip_portaudio_driver_config *conf =
            calloc(1, sizeof(quiet_lwip_portaudio_driver_config));
    const char *encoder_key = QUIET_PROFILE;
    const char *decoder_key = QUIET_PROFILE;
    const char *fname = QUIET_PROFILES_LOCATION;
    conf->encoder_opt =
            quiet_encoder_profile_filename(fname, encoder_key);
    conf->decoder_opt =
            quiet_decoder_profile_filename(fname, decoder_key);

    conf->encoder_device = Pa_GetDefaultOutputDevice();
    if (conf->encoder_device == paNoDevice) {
        printf("failed to get output device.\n");
        return -1;
    }
    const PaDeviceInfo *device_info = Pa_GetDeviceInfo(conf->encoder_device);
    conf->encoder_sample_rate = device_info->defaultSampleRate;
    conf->encoder_latency = device_info->defaultLowOutputLatency;

    conf->decoder_device = Pa_GetDefaultInputDevice();
    if (conf->decoder_device == paNoDevice) {
        printf("failed to get input device.\n");
        return -1;
    }
    device_info = Pa_GetDeviceInfo(conf->decoder_device);
    conf->decoder_sample_rate = device_info->defaultSampleRate;
    conf->decoder_latency = device_info->defaultLowOutputLatency;

    conf->encoder_sample_size = 1 << 8;
    conf->decoder_sample_size = 1 << 8;

    const uint8_t *mac = gen_rdm_bytestream(6); // MAC주소는 고냥 대충 만들어요
    const quiet_lwip_ipv4_addr ipaddr = inet_pton(local_address); // 입력으로 받은 스트링에서 끌어옵니다
    const quiet_lwip_ipv4_addr netmask = (uint32_t) 0xffffff00;  // 255.255.255.0 얘는 고정
    const quiet_lwip_ipv4_addr gateway = (ipaddr & 0xffffff00) | (0x01); // 맨 끝 한 바이트만 1로 바꿔서 게이트웨이로 씁니다

    memcpy(conf->hardware_addr, mac, 6);
    free((void *) mac);

    quiet_lwip_portaudio_interface *interface = quiet_lwip_portaudio_create(
            conf,
            htonl(ipaddr),
            htonl(netmask),
            htonl(gateway)
    );
    free(conf);

    quiet_lwip_portaudio_audio_threads *audio_threads = quiet_lwip_portaudio_start_audio_threads(interface);

    return 0;
}