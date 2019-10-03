#include <SDL2/SDL.h>
#include <unistd.h>
#include "game.h"
#include "graphics.h"

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->start();
}

Game::~Game() {

}

void Game::start() {
    Graphics graphics; // graphics starts here
    SDL_Event event;

    SDL_Renderer* renderer = graphics.getRenderer();

    SDL_RenderClear(renderer);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 5;
    rect.w = 100;
    rect.h = 200;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    graphics.flip();
    // main loop
    while (true) {
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
    }
}