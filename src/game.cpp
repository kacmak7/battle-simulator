#include <SDL2/SDL.h>
#include <unistd.h>
#include "game.h"
#include "graphics/graphics.h"

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING); //
    this->start();
}

Game::~Game() {

}

void Game::start()
    Graphics graphics; // start graphics
    //Input input;
    SDL_Event event;

    while (true) {
        //input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) {
                    SDL_Log("KEY DOWN");
                }
            }
            else if (event.type == SDL_QUIT) {
                SDL_Log("Quit");
                return;
            }
        }

    }
    //std::cout << "end" << std::endl;
}