#include "PicturePieces.h"

void startGame(SDL_Renderer* renderer, SDL_Event* e, int& numTheme, MusicGame& music)
{
    LTexture FirstScreen;
    FirstScreen.loadFromFile("image/FirstPic.png", renderer);
    FirstScreen.render(0, 0, renderer, NULL);
    SDL_RenderPresent(renderer);

    LButton ChooseTheme;
    LButton About;
    LButton Quit;

    LTexture Button;
    LTexture ChooseTheme_;
    LTexture About_;

    Button.loadFromFile("image/choice.png", renderer);
    ChooseTheme_.loadFromFile("image/ThemeChoice.png", renderer);
    About_.loadFromFile("image/About.png", renderer);

    ChooseTheme.setPosition(ChooseTheme_x, ChooseTheme_y);
    About.setPosition(About_x, About_y);
    Quit.setPosition(QuitF_x, QuitF_y);

    bool startGame_ = false;
    while(!startGame_)
    {
        SDL_PollEvent(e);
        if(e->type == SDL_QUIT) exit(1);
        SDL_RenderClear(renderer);
        FirstScreen.render(0, 0, renderer, NULL);
        if(ChooseTheme.handleEvent(e) == MOUSE_OVER_MOTION)
        {
            Button.render(ChooseTheme_x, ChooseTheme_y, renderer, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(200);
        }
        if(About.handleEvent(e) == MOUSE_OVER_MOTION)
        {
            Button.render(About_x, About_y, renderer, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(200);
        }
        if(Quit.handleEvent(e) == MOUSE_OVER_MOTION)
        {
            Button.render(QuitF_x, QuitF_y, renderer, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(200);
        }
        if(ChooseTheme.handleEvent(e) == MOUSE_DOWN)
        {
            playClickSound(music);
            bool inTheme = true;
            while(inTheme)
            {
                SDL_PollEvent(e);
                if (e->type == SDL_QUIT)
                {
                    exit(1);
                }
                ChooseTheme_.render(0, 0, renderer, NULL);
                switch(e->key.keysym.sym)
                {
                case SDLK_1:
                    numTheme = 1;
                    inTheme = false;
                    startGame_ = true;
                    break;
                case SDLK_2:
                    numTheme = 2;
                    inTheme = false;
                    startGame_ = true;
                    break;
                case SDLK_3:
                    numTheme = 3;
                    inTheme = false;
                    startGame_ = true;
                    break;
                case SDLK_b:
                    inTheme = false;
                    break;
                default:
                    inTheme = true;
                    break;
                }

                SDL_RenderPresent(renderer);
            }
        }
        if(About.handleEvent(e) == MOUSE_DOWN)
        {
            playClickSound(music);
            bool inAbout =  true;
            while(inAbout)
            {
                SDL_PollEvent(e);
                if(e->type == SDL_QUIT) exit(1);
                About_.render(0, 0, renderer, NULL);
                if(e->key.keysym.sym == SDLK_b)
                    inAbout = false;
                SDL_RenderPresent(renderer);
            }
        }
        if(Quit.handleEvent(e) == MOUSE_DOWN)
        {
            playClickSound(music);
            exit(1);
        }

        SDL_RenderPresent(renderer);
    }
    return;
}

void GameMap::LoadMap(string path)
{
    ifstream file(path);
    int x;
    for(int i = 0; i < MAX_MAP_Y; i++)
    {
        for(int j = 0; j < MAX_MAP_X; j++)
        {
            file >> x;
            game_map_.piece[i][j] = x;
            game_map_.piece_true_[i][j] = x;
        }
    }
    game_map_.fileName = path;
}

void GameMap::LoadPieces(SDL_Renderer* screen, int numTheme)
{
    string file_img[20];
    for(int i = 0; i <= MAX_TYPES; i++)
    {
        if(i < 10)
        {
            file_img[i] = "image/theme"+ to_string(numTheme) + "/0" + to_string(i) + ".png";
        }
        else file_img[i] = "image/theme"+ to_string(numTheme) + "/" + to_string(i)+".png";

        picture_pieces_[i].loadFromFile(file_img[i], screen);
    }
}

void GameMap::DrawMap(SDL_Renderer* screen)
{
    int x1 = 5;
    int x2 = PIECES_SIZE * 10;

    int y1 = 5;
    int y2 = PIECES_SIZE * 6;

    for(int  i = y1; i < y2; i += PIECES_SIZE)
    {
        for(int j = x1; j < x2; j += PIECES_SIZE)
        {
            int val = game_map_.piece[i / PIECES_SIZE][j / PIECES_SIZE];
            if(val > 0)
            {
                picture_pieces_[val].render(j, i, screen, NULL);
            }
        }
    }
}


void GameMap::setPicturePieces(int& y_empty, int& x_empty, int type, bool renderWin, bool& quit, MusicGame& music, int& movingCount)
{
    switch(type)
    {
        case KEY_UP:
            if(y_empty >= 1 && y_empty <  4 )
            {
                swap(game_map_.piece[y_empty][x_empty], game_map_.piece[y_empty++][x_empty]);
                if(renderWin)
                {
                    playSlidingSound(music);
                    movingCount ++;
                }
            }
            break;

        case KEY_RIGHT:
            if(x_empty >1 && x_empty <= 4 )
            {
                swap(game_map_.piece[y_empty][x_empty], game_map_.piece[y_empty][x_empty--]);
                if(renderWin)
                {
                    playSlidingSound(music);
                    movingCount++;
                }
            }
            break;

        case KEY_DOWN:
            if(y_empty >1 && y_empty <= 4 )
            {
                swap(game_map_.piece[y_empty][x_empty], game_map_.piece[y_empty--][x_empty]);
                if(renderWin)
                {
                    playSlidingSound(music);
                    movingCount++;
                }
            }
            break;

        case KEY_LEFT:
            if(x_empty >=1 && x_empty < 4 )
            {
                swap(game_map_.piece[y_empty][x_empty], game_map_.piece[y_empty][x_empty++]);
                if(renderWin)
                {
                    playSlidingSound(music);
                    movingCount++;
                }
            }
            break;

   }

   if(renderWin)
   {
        for (int i = 0; i < MAX_MAP_Y; i++)
       {
           for (int j = 0; j < MAX_MAP_X; j++)
           {
               if (game_map_.piece[i][j] != game_map_.piece_true_[i][j])
                   return;
           }
       }
       quit = true;
    }

}

void GameMap::randomMode(int& y_empty, int& x_empty, MusicGame& music, int& movingCount)
 {
     for(int i = 0; i <= NUMBER_RANDOM_; i++)
            {
                int tip;
                tip = rand() % 4;

                bool quit = false;
                setPicturePieces(y_empty, x_empty, tip, false, quit, music, movingCount);
            }
 }
void GameMap::functionChoice(int& y_empty, int& x_empty, int type, bool& quit, MusicGame& music, int& movingCount, bool& tryAgain)
{
    if(type == KEY_CHANGE) randomMode(y_empty, x_empty, music, movingCount);
    if(type == KEY_BACK)
    {
        quit = true;
        tryAgain = true;
    }
    if(type != 10) setPicturePieces(y_empty, x_empty, type, true, quit, music, movingCount);

}

void GameMap::WinGame(SDL_Renderer* renderer, SDL_Event event_, bool& tryAgain, MusicGame& music, int& movingCount, TTF_Font* font)
{
    LTexture winGame;
    winGame.loadFromFile("image/winGame.png", renderer);

    LTexture frameChoice;
    frameChoice.loadFromFile("image/choice.png", renderer);

    LButton TryAgain;
    LButton Quit;

    Quit.setPosition(Quit_x, Quit_y);
    TryAgain.setPosition(TryAgain_x, TryAgain_y);

    Text renderWinMove;
    renderWinMove.setText("(You've solved the puzzle in " + to_string(movingCount) + " moves)");
    renderWinMove.setColor(MAIN_COLOR_);
    renderWinMove.loadFromRenderText(font, renderer);


    bool out = false;
    while(!out)
    {
        while(SDL_PollEvent(&event_))
        {
            if (event_.type == SDL_QUIT)
            {
                exit(1);
            }
            if(Quit.handleEvent(&event_) == MOUSE_DOWN)
            {
                exit(1);
            }
            if(TryAgain.handleEvent(&event_) == MOUSE_DOWN)
            {
                playClickSound(music);
                SDL_Delay(200);
                tryAgain = true;
                out = true;
            }
            winGame.render(150, 30, renderer, NULL);
            renderWinMove.rendererText(renderer, 280, 420, NULL);
            SDL_RenderPresent(renderer);
        }
    }
}
