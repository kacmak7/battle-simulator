#include <SDL2/SDL.h>
#include <unistd.h>
#include "game.h"
#include "graphics.h"
#include "fps.h"
#include <iostream>
#include <stdlib.h>

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->start();
}

Game::~Game() {

}

void Game::start() {
    Graphics graphics;
    SDL_Event event;
    Fps fps;
    SDL_Renderer* renderer = graphics.getRenderer();
    graphics.clean();

    // test drawings
    for (int i = 0; i < 100000; i++) {
        SDL_SetRenderDrawColor(renderer, rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100, 255);
        graphics.drawPoint(rand() % graphics.SCREEN_WIDTH, rand() % graphics.SCREEN_HEIGHT);
    }
    //

    // main loop
    while (true) {
        fps.frameStart = SDL_GetTicks();
        graphics.flip();
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) {
                    SDL_Log("KEY DOWN");
                }
            } else if (event.type == SDL_QUIT) {
                SDL_Log("Quit");
                return;
            }
        }
        fps.delay();
    }
}