#ifndef FPS_H
#define FPS_H

#include <stdint.h>

class Fps {
public:
    Fps();
    ~Fps();

    static const int FRAMES_PER_SECOND;
    static const int FRAME_DELAY;

    uint32_t frameStart;
    int frameTime;

    void delay();

private:
};

#endif