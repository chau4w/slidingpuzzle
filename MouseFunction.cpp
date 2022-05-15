#include "MouseFunction.h"

LButton::LButton()
{
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentStatus = MOUSE_OUT;
}

void LButton::setPosition(int x, int y)
{
    mPosition.x = x;
    mPosition.y = y;
}

int LButton::handleEvent(SDL_Event* e)
{
    if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if(x < mPosition.x)
        {
            return MOUSE_OUT;
        }
        else if(x > mPosition.x + BUTTON_WIDTH)
        {
            return MOUSE_OUT;
        }
        else if(y < mPosition.y)
        {
            return MOUSE_OUT;
        }
        else if(y > mPosition.y + BUTTON_HEIGHT)
        {
            return MOUSE_OUT;
        }
        else if(e->type == SDL_MOUSEBUTTONDOWN)
        {
            return MOUSE_DOWN;
        }
        else return MOUSE_OVER_MOTION;
    }
}

