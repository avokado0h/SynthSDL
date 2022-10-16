#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <math.h>

#include "audio.h"
#include "render.h"
#include "input.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// forward function declarations
void initSDL(screenCtrl* sc,mySound* sndC);
void closeSDL(screenCtrl* sc,mySound* sndC);
int remapFreq(int x);

int main(int argc, char *argv[])
{

    screenCtrl  ctrl = {0};
    inputVars   myInputs = {0};
    mySound     sndCtrl;

    initSDL(&ctrl, &sndCtrl);

    // main event loop
    while (true)
    {
        // get input
        getInputs(&myInputs);
        // check if app closed
        if(myInputs.exit) break;
        // update vars
        sndCtrl.vol = myInputs.vol;
        sndCtrl.freq = remapFreq(myInputs.mouse.x);
        std::cout << remapFreq(myInputs.mouse.x) << std::endl;


        // draw bgnd color
        screenClear(&ctrl);
        // draw string
        screenTxtWrite("This sounds fucking amazing!",&ctrl, myInputs.mouse.x, myInputs.mouse.y);
        // diplay update
        screenUpdate(&ctrl);
    }

    closeSDL(&ctrl,&sndCtrl);
    return EXIT_SUCCESS;
}

void initSDL(screenCtrl* sc,mySound* sndC)
{
    // init sdl
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != EXIT_SUCCESS) 
        std::cout << "SDL2 init error: " << SDL_GetError() << std::endl;

    // init screen, renderer and font
    if (screenInit(sc, SCREEN_WIDTH, SCREEN_HEIGHT) != EXIT_SUCCESS) 
        std::cout << "SDL2 error: " << SDL_GetError() << " ttf: "<< TTF_GetError() << std::endl;

    sndC->freq = 1000; sndC->time = 0; sndC->vol = 1 / 20.0 * (2^16/2); // 20% vol
    // init soundcard and set audio buffer
    audioDeviceInit(sndC, transferSamples);
    audioDeviceEnable(sndC->audio_device);
}

void closeSDL(screenCtrl* sc,mySound* sndC)
{
    // audio clean up
    audioDeviceDisable(sndC->audio_device);
    audioDeviceClose(sndC->audio_device);
    // sdl clean up
    SDL_DestroyWindow(sc->screen);
    SDL_Quit();
}

int remapFreq(int x)
{
    int freq = (int)(11.5 * x + 50);
    return freq;
}