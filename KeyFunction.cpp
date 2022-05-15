#include"KeyFunction.h"

void functionKey(SDL_Event e, int& type)
{
    switch(e.key.keysym.sym)
    {
        case SDLK_UP:
            type = KEY_UP;
            break;
        case SDLK_DOWN:
            type = KEY_DOWN;
            break;
        case SDLK_RIGHT:
            type = KEY_RIGHT;
            break;
        case SDLK_LEFT:
            type = KEY_LEFT;
            break;
        case SDLK_x:
            type = KEY_CHANGE;
            break;
    }
}

