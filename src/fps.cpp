#include "fps.h"
#include <SDL2/SDL.h>

Fps::Fps() {}
Fps::~Fps() {}

const int Fps::FRAMES_PER_SECOND = 30;
const int Fps::FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

void Fps::delay() {
    Fps::frameTime = SDL_GetTicks() - Fps::frameStart;
    if (Fps::FRAME_DELAY > Fps::frameTime) {
        SDL_Delay(Fps::FRAME_DELAY - Fps::frameTime);
    }
}