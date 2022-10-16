#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <math.h>

#include "audio.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;

int main(int argc, char *argv[])
{

    // init stuff
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
    {
        cout << "SDL2 initialization failed! " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("ExtremelyGoodSoundingSyntesizer -EGSS- Version 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (NULL == window) 
    {
        cout << "SDL window not created :(" << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    mySound sine;
    sine.freq = 1000;
    sine.time = 0;
    sine.vol = 1 / 20.0 * (2^16/2); // 20% vol
    SDL_AudioDeviceID audio_device = audioDeviceInit(&sine, transferSamples);
    
    // main event loop
    SDL_Event windowEvent;

    int MouseX, MouseY;

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    // font init
    if(TTF_Init() != 0) {
        cout << "SDL_ttf init error: " << TTF_GetError() << endl;
        return EXIT_FAILURE;
    }

    TTF_Font *font = TTF_OpenFont("C:/Windows/Fonts/Arial.ttf", 24);
    SDL_Color White = {255, 255, 255, 0};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "put your text here", White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect Message_rect; //create a rect

    Message_rect.x = 100;  //controls the rect's x coordinate 
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 300; // controls the width of the rect
    Message_rect.h = 20; // controls the height of the rect

    audioDeviceEnable(audio_device);

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
        Message_rect.x = MouseX;
        Message_rect.y = MouseY;

        // cout << "MouseX: " << MouseX << " MouseY: " << MouseY << endl;

        //draw display
        SDL_SetRenderDrawColor(renderer, 28, 28, 28, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

        // diplay update
        SDL_RenderPresent(renderer);
    }

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);

    audioDeviceDisable(audio_device);
    audioDeviceClose(audio_device);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
