#include "unit.h"
#include "graphics.h"
#include "utils.h"
#include "class.h"
#include <iostream> // TODO to be removed

Unit::Unit(int x, int y, int team, Class* cl, Graphics* graphics) {
    this->id = Unit::currentId++;
    Unit::units[id] = this;
    this->position.x = x;
    this->position.y = y;
    this->team = team;
    this->cl = cl;
    this->graphics = graphics;
    this->graphics->drawPoint(this->position);
}

Unit::~Unit() {
    this->graphics->erasePoint(this->position);
    Unit::units.erase(this->id); // TODO: consider if it's better to null an object rather than delete from map
}

int Unit::currentId = 0;

std::map<int, Unit*> Unit::units;

void Unit::action() {
    if (isNextToEnemy()) {
        SDL_Log("True");
        //attack();
    } else {
        SDL_Log("False");
        //move();
    }
}

void Unit::move() {
    Vector2 nextPosition = this->calculateNextPosition();
    if (canMove(nextPosition)) {
        this->graphics->erasePoint(this->position);
        this->position = nextPosition;
        this->graphics->drawPoint(this->position);
    }
}

void Unit::attack() {

}

Vector2 Unit::calculateNextPosition() {
    Vector2 corner1(0, 0);
    return corner1;
}

bool Unit::canMove(Vector2 pos) {

    // TODO

    if (!units.empty()) {
        for (int i = 0; i < Unit::currentId; i++) {
            if (units.find(i) != units.end()) {
                if (units.at(i)->position == pos) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Unit::isNextToEnemy() {
    this->assignClosestEnemy();
    if (this->closestEnemy) {
        if (this->position.isNeighbor(this->closestEnemy->position)) {
            return true;
        }
    }
    return false;
}

void Unit::assignClosestEnemy() {
    // TODO: maybe pack it in generic method to not to repeat the same code in canMove()
    Vector2 corner1(0, 0);
    Vector2 corner2(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
    int maxDistance = corner1.getDistanceToPoint(corner2);
    if (!units.empty()) {
        Unit *result;
        int distance;
        for (int i = 0; i < Unit::currentId; i++) {
            if (units.find(i) != units.end()) { // check if current unit is still alive TODO to be checked
                Unit *u = units.at(i); // save current unit
                if (u->team != this->team) { // omit team mates
                    int tempDistance = this->position.getDistanceToPoint(u->position);
                    if (tempDistance < distance) {
                        distance = tempDistance;
                        result = u;
                    }
                }
            }
        }
        this->closestEnemy = result;
    } else {
        this->closestEnemy = nullptr; // if there are no enemies
    }
}

//Unit* Unit::getClosestUnit(int team) {
//  
//}
