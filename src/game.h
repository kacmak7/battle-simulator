#ifndef GAME_H

#include "graphics.h"
#include "controller.h"
#include "fps.h"

class Game {
public:
    Game();
    ~Game();
private:
    Graphics* graphics;
    SDL_Renderer* renderer;
    Fps fps;
    Controller controller;

    // Starts and loops the whole game
    void start();

    // Safely exits the program
    // TODO
    void exit();
};

#endif