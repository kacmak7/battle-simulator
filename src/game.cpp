#include <SDL2/SDL.h>
#include <iostream>
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
    std::cout << "start" << std::endl;
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
                std::cout << "QUIT" << std::endl; //test
                return;
            }
        }

    }
    std::cout << "end" << std::endl;
}