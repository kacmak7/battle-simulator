#include "fps.h"
#include <SDL2/SDL.h>

Fps::Fps() {}
Fps::~Fps() {}

const int Fps::FRAMES_PER_SECOND = 10; //temporary
const int Fps::FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

void Fps::delay() {
    this->frameTime = SDL_GetTicks() - this->frameStart;
    if (this->FRAME_DELAY > this->frameTime) {
        SDL_Delay(this->FRAME_DELAY - this->frameTime);
    }
}
