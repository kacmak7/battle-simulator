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

    Vector2 position;

    int team;

    void action();
private:

    // Counter of IDs
    static int currentId;

    // Storage of IDs
    static std::map<int, Unit*> units;

    // Unique object ID
    int id;

    // Goes towards the closest enemy
    void move();

    // Hurts the nearby enemy
    void attack();

    // Calculates the exact next position to move in
    Vector2 getNextPosition();

    // Checks if unit can move on given position
    bool* canMove(Vector2 position);

    // Checks if enemy is there
    bool isNextToEnemy();

    /* Stores the last direction that unit moved in
     * up    1
     * right 2
     * down  3
     * left  4
     * NONE  0
     */
    int lastMove;

    // Calculates the closest enemy unit
    void* assignClosestEnemy();

    // The closest enemy unit
    Unit* closestEnemy;
};

#endif
// TODO: redis?????????