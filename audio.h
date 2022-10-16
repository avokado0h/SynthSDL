#ifndef AUDIO_H
#define AUDIO_H

struct mySound
{
    double time;
    double freq;
    double vol;
};

void transferSamples(void* data, uint8_t* out, int len);

#endif /* AUDIO_H */