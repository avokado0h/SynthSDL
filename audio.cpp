#include <math.h>
#include <iostream>

#include "audio.h"

void transferSamples(void* data, uint8_t* out, int len)
{
    mySound* sound = (mySound*) data;
    int16_t* outBuffer = (int16_t*) out;
    for(int i =0; i< len/2; ++ i)
    {
        sound->time += 1.0/44100;
        outBuffer[i] = (int16_t)(sound->vol * sinf(sound->freq * sound->time * 3.1415192f * 2));
    }
}