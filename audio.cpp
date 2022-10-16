#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>

#include "audio.h"

void transferSamples(void* data, uint8_t* out, int len)
{
    mySound* sCtrl = (mySound*) data;
    int16_t* outBuffer = (int16_t*) out;

    for (int i = 0; i < len / 2; ++i)
    {
        sCtrl->time += 1.0 / MY_SAMP_RATE;
        outBuffer[i] = (int16_t)(sCtrl->vol * sinf(sCtrl->freq * sCtrl->time * 3.1415192f * 2));
    }
}

void audioDeviceInit(mySound* sndCtrl, SDL_AudioCallback funcPtr)
{
    // config structure for soundcard
    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = MY_SAMP_RATE;
    audio_spec.format = AUDIO_S16SYS;
    audio_spec.channels = 1;
    audio_spec.samples = MY_AUDIO_BUFFER;
    audio_spec.callback = funcPtr;
    audio_spec.userdata = sndCtrl; // audio callback function gets called with this struct

    // configure soundcard
    SDL_AudioDeviceID audio_device;
    sndCtrl->audio_device = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);
}

void audioDeviceEnable(SDL_AudioDeviceID id)
{
    SDL_PauseAudioDevice(id, false); // enable soundcard
}

void audioDeviceDisable(SDL_AudioDeviceID id)
{
    SDL_PauseAudioDevice(id, true); // disable soundcard
}

void audioDeviceClose(SDL_AudioDeviceID id)
{
    SDL_CloseAudioDevice(id);
}