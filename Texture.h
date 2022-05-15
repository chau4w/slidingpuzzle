#ifndef TEXTURE_H
#define TEXTURE_H

#include "Variable.h"

class LTexture
{
    public:
        LTexture();
        ~LTexture();
        bool loadFromFile(string path, SDL_Renderer* renderer);
        void free();
        void setColor(Uint8 red, Uint8 green, Uint8 blue );
        void setBlendMode(SDL_BlendMode blending);
        void setAlpha(Uint8 alpha);
        void render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip = NULL);
        int getWidth();
        int getHeight();
    private:
        SDL_Texture* mTexture;
        int mWidth;
        int mHeight;
};

bool loadMedia(SDL_Renderer* renderer, LTexture& background);

#endif // TEXTURE_H
