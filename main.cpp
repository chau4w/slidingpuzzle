#include "PicturePieces.h"

int main(int argc, char* argv[])
{
    int cc = 1;
    srand(NULL);

    LTexture gBackGround;
    LTexture gTextureText;

    bool tryAgain_ = false;
    if(!init(gWindow, gRenderer))
    {
        cout << "Failed to initialize" << endl;
    }
    else
    {
        gFont = TTF_OpenFont("font/moveCount4.TTF", 20);
        g2Font = TTF_OpenFont("font/moveCount5.ttf", 40);
            do
            {
                MusicGame music;
                playMuzikBackGround(music);

                SDL_Event e;
                int numTheme = 0;
                int moveCount = 0;

                startGame(gRenderer, &e, numTheme, music);
                gBackGround.loadFromFile("image/theme" + to_string(numTheme) + "/backGround" + to_string(numTheme)+ ".png", gRenderer);
                tryAgain_ = false;

                GameMap game_map_;
                int x = 4;
                int y = 4;
                game_map_.LoadMap("image/map.txt");
                game_map_.LoadPieces(gRenderer, numTheme);
                game_map_.randomMode(y, x, music, moveCount);

                bool quit = false;
                while(!quit)
                {
                    Text renderMove;
                    renderMove.setColor(MAIN_COLOR_);

                    if( SDL_PollEvent(&e) != 0)
                    {
                        if(e.type == SDL_QUIT)
                        {
                            quit = true;
                        }
                        else if(e.type == SDL_KEYDOWN)
                        {
                            functionKey(e, type);
                            game_map_.functionChoice(y, x, type, quit, music, moveCount);
                        }
                    }
                    SDL_RenderClear(gRenderer);
                    gBackGround.setAlpha(ALPHA_BACK_GROUND);
                    gBackGround.render(0, 0, gRenderer);
                    game_map_.DrawMap(gRenderer);

                    renderMove.setText("Your moves: " + to_string(moveCount));
                    renderMove.loadFromRenderText(g2Font, gRenderer);
                    renderMove.rendererText(gRenderer, 550, 250, NULL);
                    SDL_RenderPresent(gRenderer);
                }
                SDL_RenderClear(gRenderer);
                gBackGround.setAlpha(ALPHA_BACK_GROUND);
                gBackGround.render(0, 0, gRenderer);
                game_map_.WinGame(gRenderer, e, tryAgain_, music,moveCount, gFont);

            }while(tryAgain_ == true);
        }
    close();
    return 0;
}

