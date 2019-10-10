#ifndef GAME_H

#include "graphics.h"
#include "fps.h"

class Game {
public:
    Game();
    ~Game();
private:
    Graphics* graphics;
    SDL_Event event;
    Fps fps;
    SDL_Renderer* renderer;

    void start();
    void exit();
        
};

#endif