#ifndef AUDIO_H
#define AUDIO_H

#define MY_SAMP_RATE 44100

struct mySound
{
    double time;
    double freq;
    double vol;
};

void transferSamples(void* data, uint8_t* out, int len);

SDL_AudioDeviceID audioDeviceInit(mySound* sndCtrl, SDL_AudioCallback funcPtr);

void audioDeviceEnable(SDL_AudioDeviceID id);
void audioDeviceDisable(SDL_AudioDeviceID id);
void audioDeviceClose(SDL_AudioDeviceID id);

#endif /* AUDIO_H */