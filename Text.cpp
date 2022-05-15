#include "Text.h"

Text::Text()
{
    int width = 0;
    int height = 0;

    textColor.r = 0;
    textColor.g = 0;
    textColor.b = 0;
    texture = NULL;
    stringVal = "";
}

Text::~Text()
{
    free();
}

bool Text::loadFromRenderText(TTF_Font* font, SDL_Renderer* renderer)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, stringVal.c_str(), textColor);
    if(textSurface)
    {
        texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        width = textSurface->w;
        height = textSurface->h;
        SDL_FreeSurface(textSurface);
    }
    return texture != NULL;
}

void Text::setColor(int red, int green, int blue)
{
    textColor.r = red;
    textColor.g = green;
    textColor.b = blue;
}

void Text::setColor(int typeColor)
{
    switch(typeColor)
    {
        case BLACK_:
            textColor = {0, 0, 0};
            break;
        case WHITE_:
            textColor= { 255, 255, 255 };
            break;
        case RED_:
            textColor = { 152, 17, 21};
            break;
        case GREEN_:
            textColor = { 0,255,0 };
            break;
        case PURPLE_:
            textColor = { 0,0,255 };
            break;
        case YELLOW_:
            textColor = { 242, 171, 57 };
            break;
        case BLUE_:
            textColor = { 0,255,255 };
            break;
        case PINK_:
            textColor = { 255, 0, 255 };
            break;
        case MAIN_COLOR_:
            textColor = {7, 106, 103};
            break;
    }
}

void Text::rendererText(SDL_Renderer* render, int x, int y, SDL_Rect* clip)
{
    SDL_Rect renderQuad = {x, y, width, height};
    if(clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(render, texture, clip, &renderQuad, 0, NULL, SDL_FLIP_NONE);

}

int Text::getWidth() const
{
    return width;
}

int Text::getHeight() const
{
    return height;
}

void Text::setText(const string& textInput)
{
    stringVal = textInput;
}

string Text::getText() const
{
    return stringVal;
}

void Text::free()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
}
