#ifndef UNIT_H
#define UNIT_H

#include "graphics.h"
#include "utils.h"
#include <map>

class Unit {
public:
    Unit(int x, int y, int team, Graphics* graphics);
    ~Unit();

    Graphics* graphics;
    Position position;
    int team;

    void action();
private:

    static int currentId;

    static std::map<int, Unit*> units;

    int id;

    // Goes towards the closest enemy
    void move();

    // Hurts the nearby enemy
    void attack();

    // Returns the exact next position of the unit
    Position getNextPosition();

    // Calculates and return the closest enemy unit
    Unit getClosestEnemy();
};

#endif
//TODO: redis?????????