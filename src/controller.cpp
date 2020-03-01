#include <SDL2/SDL.h>
#include "controller.h"
#include "unit.h"
#include "class.h"

Controller::Controller() {}
Controller::~Controller() {}

void Controller::process() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            if (event.key.repeat == 0) {
                SDL_Log("KEY DOWN");
            }
            break;
        case SDL_QUIT:
            this->exit();
            //return; TODO END PROGRAM HERE
            break;
        case SDL_MOUSEBUTTONDOWN:
            Vector2 pos(event.motion.x, event.motion.y);
            //this->deployUnits(pos);
            SDL_Log("Units successfully deployed");
            //SDL_Log("Deployed to (" + event.motion.x + event.motion.y + ")".c_str());
            break;
        }
    }
}

// TODO safe exit on demand
void Controller::exit() {
    SDL_Log("Quit");
}
