#include "Muzik.h"

MusicGame::MusicGame()
{
    muzikBackGround = NULL;
    clickSound = NULL;
    slidingSound = NULL;
}

MusicGame::~MusicGame()
{
    free();
}

void MusicGame::loadMusic()
{
    muzikBackGround = Mix_LoadMUS("muzik/backGround.mp3");

    clickSound = Mix_LoadWAV("muzik/clickSound.wav");
    slidingSound = Mix_LoadWAV("muzik/slidingSound.wav");
}

Mix_Music* MusicGame::getMuzikBackground() const
{
    return muzikBackGround;
}

Mix_Chunk* MusicGame::getClickSound() const
{
    return clickSound;
}

Mix_Chunk* MusicGame::getSlidingSound() const
{
    return slidingSound;
}

void MusicGame::free()
{
    Mix_FreeMusic(muzikBackGround);

    Mix_FreeChunk(clickSound);
    Mix_FreeChunk(slidingSound);

    muzikBackGround = NULL;
    clickSound = NULL;
    slidingSound = NULL;
}

void playMuzikBackGround(MusicGame& muzikBackGround)
{
    muzikBackGround.loadMusic();
    Mix_PlayMusic(muzikBackGround.getMuzikBackground(), -1);
}

void playClickSound(MusicGame& clickSound)
{
    clickSound.loadMusic();
    Mix_PlayChannel(-1, clickSound.getClickSound(), 0);
}

void playSlidingSound(MusicGame& slidingSound)
{
    slidingSound.loadMusic();
    Mix_PlayChannel(-1, slidingSound.getSlidingSound(), 0);
}
