#ifndef MOUSE_FUNCTION_H
#define MOUSE_FUNCTION_H

#include "Texture.h"

enum ButtonMouse
{
    MOUSE_OUT = 0,
    MOUSE_OVER_MOTION = 1,
    MOUSE_DOWN = 2,
    MOUSE_UP = 3,
    MOUSE_TOTAL = 4
};

class LButton
{
    public:
        LButton();
        void setPosition(int x, int y);
        int handleEvent(SDL_Event* e);
        void render(SDL_Renderer* renderer);
        int getStatus();
    private:
        SDL_Point mPosition;
        ButtonMouse mCurrentStatus;

};



#endif // MOUSE_FUNCTION_H
