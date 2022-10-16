#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct screenCtrl
{
    SDL_Window* screen;
    SDL_Renderer* renderer;
    TTF_Font* font;
};

int screenInit(screenCtrl* sc, int w, int h);

void screenClear(screenCtrl* sc);
void screenUpdate(screenCtrl* sc);

void screenTxtWrite(const char *txt, screenCtrl* sc, int x, int y);

#endif /* RENDER_H */