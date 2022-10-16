#ifndef AUDIO_H
#define AUDIO_H

#define MY_SAMP_RATE    44100
#define MY_AUDIO_BUFFER 512

struct mySound
{
    SDL_AudioDeviceID audio_device;
    double time;
    double freq;
    double vol;
};

void transferSamples(void* data, uint8_t* out, int len);
void audioDeviceInit(mySound* sndCtrl, SDL_AudioCallback funcPtr);
void audioDeviceEnable(SDL_AudioDeviceID id);
void audioDeviceDisable(SDL_AudioDeviceID id);
void audioDeviceClose(SDL_AudioDeviceID id);

#endif /* AUDIO_H */