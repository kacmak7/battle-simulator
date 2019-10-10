#ifndef UNIT_H
#define UNIT_H

#include "graphics.h"

class Unit {
public:
    Unit(int x, int y, int team, Graphics* graphics);
    ~Unit();

    Graphics* graphics;

    int x; // position
    int y; // position
    int team;
private:

};

#endif
//TODO: feature bug: covering of the units
//TODO: redis?????????