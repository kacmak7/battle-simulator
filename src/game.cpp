#include <SDL2/SDL.h>
#include <unistd.h>
#include "game.h"
#include "graphics.h"
#include "fps.h"
#include <iostream>

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

    // test
    graphics.drawRectangle(10, 10, 60, 30);

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