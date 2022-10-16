#include <SDL2/SDL.h>
#include <iostream>

#include "input.h"

void getInputs(inputVars* iv)
{
    SDL_Event windowEvent;

    SDL_GetMouseState(&iv->mouse.x, &iv->mouse.y);

    SDL_PollEvent(&windowEvent);

    if (windowEvent.type == SDL_QUIT) iv->exit = true;

    if (windowEvent.type == SDL_MOUSEWHEEL)
    {
        if(windowEvent.wheel.y > 0)         iv->vol += 100;
        else if(windowEvent.wheel.y < 0)    iv->vol -= 100;
    }
}