#ifndef MUZIK_H
#define MUZIK_H

#include "Variable.h"

class MusicGame
{
    public:
        MusicGame();
        ~MusicGame();
        void loadMusic();

        Mix_Music* getMuzikBackground() const;

        Mix_Chunk* getClickSound() const;
        Mix_Chunk* getSlidingSound() const;



        void free();
    private:
        Mix_Music* muzikBackGround;

        Mix_Chunk* clickSound;
        Mix_Chunk* slidingSound;
};

void playMuzikBackGround(MusicGame& muzikBackGround);
void playClickSound(MusicGame& clickSound);

void playSlidingSound(MusicGame& slidingSound);
#endif // MUZIK_H
