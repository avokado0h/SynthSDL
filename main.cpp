#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>

const int WIDTH = 800, HEIGHT = 600;
using namespace std;

void transferSamples(void* data, uint8_t* out, int len);

struct mySound
{
    double time;
    double freq;
    double vol;
};

int main(int argc, char *argv[])
{

    // init stuff
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) 
    {
        cout << "SDL2 initialization failed! " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("ExtremelyGoodSoundingSyntesizer -EGSS- Version 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    if (NULL == window) 
    {
        cout << "SDL window not created :(" << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    mySound sine = {0.0, 1000.0, 5000.0};

    // opening an audio device:
    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = 44100;
    audio_spec.format = AUDIO_S16SYS;
    audio_spec.channels = 1;
    audio_spec.samples = 1024;
    audio_spec.callback = transferSamples;
    audio_spec.userdata = &sine;


    SDL_AudioDeviceID audio_device;
    audio_device = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);

    // main event loop
    SDL_Event windowEvent;

int MouseX, MouseY;
cout << "eyoooo\n";
    SDL_PauseAudioDevice(audio_device, 0); // start sine wave generator
    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                break;
            }

            if (windowEvent.type == SDL_MOUSEWHEEL)
            {
                if(windowEvent.wheel.y > 0) sine.vol += 100;
                else if(windowEvent.wheel.y < 0) sine.vol -= 100;
            }
        }

        SDL_GetMouseState(&MouseX, &MouseY);
        cout << "MouseX: " << MouseX << " MouseY: " << MouseY << endl;
    }

    SDL_PauseAudioDevice(audio_device, 1); // stop sine wave generator
    SDL_CloseAudioDevice(audio_device);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

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