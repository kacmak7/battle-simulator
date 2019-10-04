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
    Graphics graphics; // graphics starts here
    SDL_Event event;
    Fps fps;
    SDL_Renderer* renderer = graphics.getRenderer();
    SDL_RenderClear(renderer);

    // test drawings
    for (int i = 0; i < 1000; i++) {
    //TODO: get rid of globals.h
        SDL_SetRenderDrawColor(renderer, rand()%155 + 100, rand()%155 + 100, rand()%155 + 100, 255);
        graphics.drawPoint(rand()%100, rand()%200);
    }
    //

    // main loop
    while (true) {
        fps.frameStart = SDL_GetTicks();
        SDL_Log("Frame");
        graphics.flip();
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) {
                    SDL_SetWindowFullscreen(graphics.getWindow(), SDL_WINDOW_FULLSCREEN);
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