#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
 
 #pragma comment(linker, "/SUBSYSTEM:CONSOLE")

const int WIDTH = 800, HEIGHT = 600;
using namespace std;

void testPrint();

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

    // opening an audio device:
    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = 44100;
    audio_spec.format = AUDIO_S16SYS;
    audio_spec.channels = 1;
    audio_spec.samples = 1024;
    audio_spec.callback = NULL;

    SDL_AudioDeviceID audio_device;
    audio_device = SDL_OpenAudioDevice(NULL, 0, &audio_spec, NULL, 0);

    // main event loop
    SDL_Event windowEvent;

        // pushing 3 seconds of samples to the audio buffer:
    float x = 0;
    for (int i = 0; i < audio_spec.freq * 3; i++) {
        x += .010f;

        // SDL_QueueAudio expects a signed 16-bit value
        // note: "5000" here is just gain so that we will hear something
        int16_t sample = sin(x * 4) * 5000;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }

    // unpausing the audio device (starts playing):
    SDL_PauseAudioDevice(audio_device, 0);
    testPrint();

    SDL_Delay(3000);

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
    }

    SDL_CloseAudioDevice(audio_device);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

void testPrint()
{
    cout << "test\n";
}