#include "PicturePieces.h"
#include "Time.h"

int main(int argc, char* argv[])
{
    bool loseGame = false;
    bool tryAgain_ = false;

    int totalTime = 0;
    int timeLimit = 30;
    srand(NULL);

    LTexture gBackGround;
    LTexture gTextureText;
    Timer time_;

    if(!init(gWindow, gRenderer))
    {
        cout << "Failed to initialize" << endl;
    }
    else
    {
        gFont = TTF_OpenFont("font/moveCount4.TTF", 20);
        g2Font = TTF_OpenFont("font/moveCount6.ttf", 40);
        g3Font = TTF_OpenFont("font/moveCount5.ttf", 40);
            do
            {
                MusicGame music;
                playMuzikBackGround(music);

                SDL_Event e;
                int numTheme = 0;
                int moveCount = 0;

                vector <int>rankRecord;
                sortRecord(rankRecord, path_);

                startGame(gRenderer, &e, numTheme, music, rankRecord, g3Font);
                gBackGround.loadFromFile("image/theme" + to_string(numTheme) + "/backGround" + to_string(numTheme)+ ".png", gRenderer);
                tryAgain_ = false;

                GameMap game_map_;
                int x = 4;
                int y = 4;
                game_map_.LoadMap("image/map4.txt");
                game_map_.LoadPieces(gRenderer, numTheme);
                game_map_.randomMode(y, x, music, moveCount);

                bool quit = false;
                time_.start();
                    Text renderMove;

                while(!quit)
                {
                    if(numTheme == 1)
                        renderMove.setColor(RED_);
                    if(numTheme == 2)
                        renderMove.setColor(GREEN_);
                    if(numTheme == 3)
                        renderMove.setColor(BLACK_);

                    if( SDL_PollEvent(&e) != 0)
                    {
                        if(e.type == SDL_QUIT)
                        {
                            quit = true;
                            exit(1);
                        }
                        else if(e.type == SDL_KEYDOWN)
                        {
                            functionKey(e, type);
                            game_map_.functionChoice(y, x, type, quit, music, moveCount, tryAgain_);
                        }
                    }
                    SDL_RenderClear(gRenderer);

                    gBackGround.setAlpha(ALPHA_BACK_GROUND);
                    gBackGround.render(0, 0, gRenderer);
                    game_map_.DrawMap(gRenderer);

                    int thoiGian = MAX_TIME - time_.getTicks() / 1000;
                    string s = to_string(thoiGian);
                    totalTime = thoiGian;
                    renderMove.setText(s);
                    renderMove.loadFromRenderText(g2Font, gRenderer);
                    renderMove.rendererText(gRenderer, 700, 110, NULL);

                    renderMove.setText(to_string(moveCount));
                    renderMove.loadFromRenderText(g2Font, gRenderer);
                    renderMove.rendererText(gRenderer, 710, 220, NULL);

                    if(thoiGian <= 0)
                    {
                        loseGame = true;
                        quit = true;
                    }
                    SDL_RenderPresent(gRenderer);
                }
                SDL_RenderClear(gRenderer);
                //gBackGround.setAlpha(ALPHA_BACK_GROUND);
                gBackGround.render(0, 0, gRenderer);
                if(tryAgain_ != true && loseGame != true)
                {
                    ofstream file;
                    file.open(path_, ios::app);
                    file << moveCount << " ";
                    game_map_.WinGame(gRenderer, e, tryAgain_, music,moveCount, gFont, totalTime);
                }
                else if(tryAgain_ != true && loseGame == true)
                {
                    game_map_.LoseGame(gRenderer, e, tryAgain_, music);
                }
            }while(tryAgain_ == true);
        }
    close();
    return 0;
}

