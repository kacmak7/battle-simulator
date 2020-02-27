#ifndef UNIT_H
#define UNIT_H

#include "graphics.h"
#include "utils.h"
#include "class.h"
#include <map>

class Unit {
public:
    Unit(int x, int y, int team, Class* cl, Graphics* graphics);
    ~Unit();

    /*
     * Performs attack or move depending on position of the enemy
     */
    void action();

private:
    Class* cl;
    /*
     * The only graphics API
     */
    Graphics* graphics;

    /*
     * Stores current position
     */
    Vector2 position;
    
    /*
     * Defines which team unit belongs to. Needed to define who's an ally and who's not
     */
    int team;

    /*
     * Counter of all IDs
     */
    static int currentId;

    /*
     * Storage of all IDs
     */
    static std::map<int, Unit*> units;

    /*
     * Unique object ID
     */
    int id;

    /*
     * Goes towards the closest enemy
     */
    void move();

    /*
     * Hurts the nearby enemy
     */
    void attack();

    /*
     * Calculates and assigns the next position
     */
    Vector2 calculateNextPosition();

    /*
     * True if unit is allowed to move to given position
     */
    bool canMove(Vector2 position);

    /*
     * True if enemy is next to the Unit
     */
    bool isNextToEnemy();

    /* Stores the last direction that unit moved in
     * up    1
     * right 2
     * down  3
     * left  4
     * NONE  0
     */
    int lastMove;

    /*
     * Saves the closest enemy unit
     */
    void assignClosestEnemy();

    /*
     * The closest enemy unit
     */
    Unit* closestEnemy;

    /*
     * Calculates the closest unit (no matter if it's ally or enemy)
     */
    Unit* getClosestUnit(int team);
};

#endif
