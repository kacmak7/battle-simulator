#include <SDL2/SDL.h>
#include <unistd.h>
#include "game.h"
#include "graphics.h"
#include "fps.h"
#include "unit.h"
#include "controller.h"
#include "class.h"
#include <iostream>
#include <stdlib.h>

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->graphics = new Graphics();
    this->renderer = graphics->getRenderer();
    this->controller = new Controller();
    this->start();
}

Game::~Game() {}

void Game::start() {
    graphics->clean();

    // test
    Rgb red(255, 0, 0);
    Rgb green(0, 255, 0);
    Class* fc = new Class(100, 25, red);
    Class* sc = new Class(150, 25, green);
    Vector2 pos(400, 550);
    Unit unit(pos, 0, fc, graphics);
    Vector2 pos1(470, 600);
    Unit unit1(pos1, 1, sc, graphics);
    Vector2 pos2(1, 11);
    Unit unit2(pos2, 0, fc, graphics);
    Vector2 pos3(18, 15);
    Unit unit3(pos3, 0, fc, graphics);
    //

    // main loop
    while (true) {
        fps.frameStart = SDL_GetTicks();
        graphics->flip();
        SDL_Log("x");
        unit.action();
        unit1.action();
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

// TODO safe exit on demand
void Game::exit() {
    SDL_Log("Quit");
}
