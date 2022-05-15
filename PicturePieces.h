#ifndef PICTURE_PIECES_H
#define PICTURE_PIECES_H

#include "Variable.h"
#include "KeyFunction.h"
#include "MouseFunction.h"
#include "Muzik.h"
#include "Text.h"

#define   MAX_TYPES 17


class Pieces : public LTexture
{
    public:
        Pieces(){;}
        ~Pieces(){;}
};

class GameMap
{
    public:
        GameMap() {;}
        ~GameMap() {;}

        void LoadMap(string path);
        void LoadPieces(SDL_Renderer* screen, int numTheme);
        void DrawMap(SDL_Renderer* screen);

        void setPicturePieces(int& y_empty, int& x_empty, int type, bool renderWin, bool& quit, MusicGame& music, int& movingCount);
        void randomMode(int& y_empty, int& x_empty, MusicGame& music, int& movingCount);
        void functionChoice(int& y_empty, int& x_empty, int type, bool& quit, MusicGame& music, int& movingCount, bool& tryAgain);
        void WinGame(SDL_Renderer* renderer, SDL_Event event_, bool& tryAgain, MusicGame& music, int& movingCount, TTF_Font* font);

    private:
        int x_empty_ = 4;
        int y_empty_ = 4;
        MAP game_map_;
        Pieces picture_pieces_[MAX_TYPES + 1];
};
void startGame(SDL_Renderer* renderer, SDL_Event* e, int& numTheme, MusicGame& music);

#endif // PICTURE_PIECES_H
