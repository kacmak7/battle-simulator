#include <SDL2/SDL.h>
#include "controller.h"
#include "unit.h"
#include "class.h"

Controller::Controller() {}
Controller::~Controller() {}

void Controller::process() {
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
            Vector3 pos(event.motion.x, event.motion.y);
            //this->deployUnits(pos);
            SDL_Log("Units successfully deployed");
            //SDL_Log("Deployed to (" + event.motion.x + event.motion.y + ")".c_str());
            break;
        }
    }
}

void Controller:getTeam(&event) {
    //SDL_Keycode nums [10] = { SDLK_0, SDLK_1, SDLK_2, SDLK_3};
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_0) {
        SDL_Log("000000");
    }
}

// TODO safe exit on demand
void Controller::exit() {
    SDL_Log("Quit");
}
