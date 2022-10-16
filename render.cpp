#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <math.h>

#include "render.h"

int screenInit(screenCtrl* sc, int w, int h)
{
    // screen init
    sc->screen = SDL_CreateWindow("ExtremelyGoodSoundingSyntesizer -EGSS- Version 1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    if(sc->screen == NULL) return EXIT_FAILURE;

    // renderer init
    sc->renderer = SDL_CreateRenderer(sc->screen, -1, SDL_RENDERER_SOFTWARE);
    if(sc->renderer == NULL) return EXIT_FAILURE;

    // font init
    if(TTF_Init() != 0) return EXIT_FAILURE;
    sc->font = TTF_OpenFont("C:/Windows/Fonts/Arial.ttf", 24);

    return EXIT_SUCCESS;
}

void screenClear(screenCtrl* sc)
{
    SDL_SetRenderDrawColor(sc->renderer, 28, 28, 28, 255);
    SDL_RenderClear(sc->renderer);
}

void screenUpdate(screenCtrl* sc)
{
    SDL_RenderPresent(sc->renderer);
}

void screenTxtWrite(const char *txt, screenCtrl* sc, int x, int y)
{
    SDL_Color White = {255, 255, 255, 0};

    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sc->font, txt, White);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(sc->renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = x; Message_rect.y = y;
    Message_rect.w = 300; Message_rect.h = 20;

    SDL_RenderCopy(sc->renderer, Message, NULL, &Message_rect);
    SDL_DestroyTexture(Message);
}