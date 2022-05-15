#ifndef VARIABLE_H
#define VARIABLE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;
static TTF_Font* gFont = NULL;
static TTF_Font* g2Font = NULL;

static int type;

const int SCREEN_WIDTH = 950;
const int SCREEN_HEIGHT = 650;
const int ALPHA_BACK_GROUND = 100;

const int PIECES_SIZE = 100;
const int MAX_MAP_X = 9;
const int MAX_MAP_Y = 6;

const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 100;
const int MOUSE_TOTAL_STATUS = 4;

const int Quit_x = 540;
const int Quit_y = 525;

const int TryAgain_x = 300;
const int TryAgain_y = 520;

const int ChooseTheme_x = 750;
const int ChooseTheme_y = 200;

const int About_x = 750;
const int About_y = 330;

const int QuitF_x = 750;
const int QuitF_y = 480;

#define NUMBER_RANDOM_ 50
typedef struct MAP
{

    int piece[MAX_MAP_Y][MAX_MAP_X];
    int piece_true_[MAX_MAP_Y][MAX_MAP_X];
    string fileName;
};

bool init(SDL_Window* window, SDL_Renderer*& renderer);
void close();

#endif // VARIABLE_H
