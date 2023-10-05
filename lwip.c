//
// Created by Administrator on 2023-10-05.
//

#include "lwip.h"

#include <unistd.h>
#include <string.h>
#include <quiet-lwip-portaudio.h>
#include <quiet-lwip/lwip-socket.h>

#include "opt.h"
#include "util.h"
#include "relay.h"

int initialized;
pthread_mutex_t lwip_init_lock;

quiet_lwip_portaudio_audio_threads *lwip_audio_threads;
quiet_lwip_portaudio_interface *lwip_interface;

int start_lwip_portaudio(uint8_t *mac, uint32_t ipaddr, uint32_t netmask, uint32_t gateway) {
    pthread_mutex_lock(&lwip_init_lock);

    if (initialized) {
        pthread_mutex_unlock(&lwip_init_lock);
        log_message("start_lwip_portaudio() already initialized.");
        return 0;
    }

    PaError err = Pa_Initialize();
    if (err != paNoError) {
        log_message("start_lwip_portaudio() failed to initialize port audio, %s", Pa_GetErrorText(err));
        pthread_mutex_unlock(&lwip_init_lock);
        return -1;
    }

    PaDeviceIndex output_device = Pa_GetDefaultOutputDevice();
    if (output_device == paNoDevice) {
        log_message("start_lwip_portaudio() failed to get output device.");
        pthread_mutex_unlock(&lwip_init_lock);
        return -1;
    }

    PaDeviceIndex input_device = Pa_GetDefaultInputDevice();
    if (input_device == paNoDevice) {
        log_message("start_lwip_portaudio() failed to get input device.");
        pthread_mutex_unlock(&lwip_init_lock);
        return -1;
    }

    const quiet_encoder_options *encoder_opt = quiet_encoder_profile_filename(QUIET_PROFILE_PATH, QUIET_PROFILE);
    if (encoder_opt == NULL) {
        log_message("start_lwip_portaudio() failed to get encoder profile.");
        pthread_mutex_unlock(&lwip_init_lock);
        return -1;
    }

    const quiet_decoder_options *decoder_opt = quiet_decoder_profile_filename(QUIET_PROFILE_PATH, QUIET_PROFILE);
    if (decoder_opt == NULL) {
        log_message("start_lwip_portaudio() failed to get decoder profile.");
        pthread_mutex_unlock(&lwip_init_lock);
        return -1;
    }

    quiet_lwip_portaudio_driver_config *conf = calloc(1, sizeof(quiet_lwip_portaudio_driver_config));

    conf->encoder_opt = encoder_opt;
    conf->decoder_opt = decoder_opt;

    conf->encoder_device = output_device;
    const PaDeviceInfo *device_info = Pa_GetDeviceInfo(conf->encoder_device);
    conf->encoder_sample_rate = device_info->defaultSampleRate;
    conf->encoder_latency = device_info->defaultLowOutputLatency;

    conf->decoder_device = input_device;
    device_info = Pa_GetDeviceInfo(conf->decoder_device);
    conf->decoder_sample_rate = device_info->defaultSampleRate;
    conf->decoder_latency = device_info->defaultLowOutputLatency;

    conf->encoder_sample_size = 1 << 7;
    conf->decoder_sample_size = 1 << 7;

    memcpy(conf->hardware_addr, mac, 6);
    lwip_interface = quiet_lwip_portaudio_create(conf, htonl(ipaddr), htonl(netmask),
                                                 htonl(gateway));
    free(conf);

    lwip_audio_threads = quiet_lwip_portaudio_start_audio_threads(lwip_interface);
    initialized = 1;

    pthread_mutex_unlock(&lwip_init_lock);

    return 0;
}

int stop_lwip_portaudio() {
    pthread_mutex_lock(&lwip_init_lock);

    if (!initialized) {
        log_message("stop_lwip_portaudio() not initialized.");
        pthread_mutex_unlock(&lwip_init_lock);
        return 0;
    }

    quiet_lwip_portaudio_stop_audio_threads(lwip_audio_threads);
    quiet_lwip_portaudio_destroy(lwip_interface);

    PaError error = Pa_Terminate();
    if (error != paNoError) {
        log_message("stop_lwip_portaudio() failed to terminate port audio, %s", Pa_GetErrorText(error));
        pthread_mutex_unlock(&lwip_init_lock);
        return -1;
    }

    pthread_mutex_unlock(&lwip_init_lock);

    return 0;
}