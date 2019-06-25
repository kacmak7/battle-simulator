#include <SDL2/SDL.h>
#include <spdlog/spdlog.h>
#include <unistd.h>
#include "game.h"
#include "graphics/graphics.h"

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING); //
    this->start();
}

Game::~Game() {

}

void Game::start() {
    spdlog::info("Game started");
    Graphics graphics; // start graphics
    //Input input;
    SDL_Event event;

    while (true) {
        //input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) {

                }
            }
            else if (event.type == SDL_QUIT) {
                spdlog::info("QUIT");
                return;
            }
        }

    }
    //std::cout << "end" << std::endl;
}