#ifndef TEXT_H
#define TEXT_H

#include "Variable.h"

enum TextColor
{
    BLACK_ = 0,
    WHITE_ = 1,
    RED_ = 2,
    GREEN_ = 3,
    PURPLE_ = 4,
    YELLOW_ = 5,
    BLUE_ = 6,
    PINK_ =7,
    MAIN_COLOR_ = 8

};

class Text
{
    public:
        Text();
        ~Text();

        bool loadFromRenderText(TTF_Font* font, SDL_Renderer* renderer);
        void setColor(int red, int green, int blue);
        void setColor(int typeColor);

        void rendererText(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL);

        int getWidth() const;
        int getHeight() const;

        void setText(const string& textInput);
        string getText() const;

        void free();
    private:
        string stringVal;
        SDL_Color textColor;
        SDL_Texture* texture;
        int width;
        int height;
};

#endif // TEXT_H
