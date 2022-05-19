#include "Variable.h"

class Timer
{
    public:
        Timer();
        void start();
        void stop();
        void pause();
        void unpause();

        int getTicks();

        bool isStarted();
        bool isPaused();

    private:
        int mStartTicks;
        int mPausedTicks;

        bool mPaused;
        bool mStarted;
};
