#include <SDL2/SDL.h>
#include "controller.h"
#include "unit.h"
#include "class.h"

Controller::Controller() {}
Controller::~Controller() {}

void Controller::process() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            if (event.key.repeat == 0) {
                SDL_Log("KEY DOWN");
            }
        } else if (event.type == SDL_QUIT) {
            this->exit();
            return;
        }
    }
}

// TODO safe exit on demand
void Controller::exit() {
    SDL_Log("Quit");
}
