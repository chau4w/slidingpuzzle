#ifndef FUNCTION_H
#define FUNCTION_H

#include "Texture.h"

enum KeyDirections
{
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_CHANGE
};
void functionKey(SDL_Event e, int& type);


#endif // FUNCTION_H
