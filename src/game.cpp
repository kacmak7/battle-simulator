#include <SDL2/SDL.h>
#include <unistd.h>
#include "game.h"
#include "graphics.h"
#include "fps.h"
#include "unit.h"
#include <iostream>
#include <stdlib.h>

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->graphics = new Graphics();
    this->renderer = graphics->getRenderer();
    this->start();
}

Game::~Game() {}

void Game::start() {
    graphics->clean();

    // test drawings
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    Unit unit(10, 10, 0, graphics);
    //

    // main loop
    while (true) {
        fps.frameStart = SDL_GetTicks();
        graphics->flip();
        SDL_Log("x");
        SDL_Log("frame");
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
        fps.delay();
    }
}

// TODO
void Game::exit() {
    SDL_Log("Quit");
}