#ifndef UNIT_H
#define UNIT_H

#include "graphics.h"
#include "utils.h"

class Unit {
public:
    Unit(int x, int y, int team, Graphics* graphics);
    ~Unit();

    Graphics* graphics;
    Utils::Position position;
    int team;

    void move();
private:
    Utils::Position getNextPosition();
};

#endif
//TODO: feature bug: covering of the units
//TODO: redis?????????