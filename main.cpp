#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <math.h>

#include "audio.h"
#include "render.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{

    screenCtrl ctrl = {0};

    // init sdl
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) 
        std::cout << "SDL2 init error: " << SDL_GetError() << std::endl;
    // init screen, renderer and font
    if (screenInit(&ctrl, SCREEN_WIDTH, SCREEN_HEIGHT) == EXIT_FAILURE) 
        std::cout << "SDL2 error: " << SDL_GetError() << " ttf: "<< TTF_GetError() << std::endl;

    mySound sine;
    sine.freq = 1000; sine.time = 0; sine.vol = 1 / 20.0 * (2^16/2); // 20% vol
    SDL_AudioDeviceID audio_device = audioDeviceInit(&sine, transferSamples);
    
    audioDeviceEnable(audio_device);

    // main event loop
    SDL_Event windowEvent;
    int MouseX, MouseY;
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

        // get input
        SDL_GetMouseState(&MouseX, &MouseY);

        //draw display
        screenClear(&ctrl);

        screenTxtWrite("Was Geht aaab!",&ctrl, MouseX, MouseY);

        // diplay update
        screenUpdate(&ctrl);
    }


    audioDeviceDisable(audio_device);
    audioDeviceClose(audio_device);

    SDL_DestroyWindow(ctrl.screen);
    SDL_Quit();

    return EXIT_SUCCESS;
}
