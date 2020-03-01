#include "unit.h"
#include "graphics.h"
#include "utils.h"
#include "class.h"
#include <iostream> // TODO to be removed

Unit::Unit(Vector2 position, int team, Class* cl, Graphics* graphics) {
    this->id = Unit::currentId++;
    Unit::units[id] = this;
    this->position = position;
    this->team = team;
    this->cl = cl;
    this->graphics = graphics;
    this->graphics->setDrawColor(cl->getColor(), 0);
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
        attack();
    } else {
        SDL_Log("False");
        move();
    }
}

void Unit::move() {
    Vector2 nextPosition = this->calculateNextPosition();
    if (canMove(nextPosition)) {
        this->graphics->erasePoint(this->position);
        this->position = nextPosition;
        this->graphics->setDrawColor(cl->getColor(), 0);
        this->graphics->drawPoint(this->position);
    }
}

void Unit::attack() {
    this->closestEnemy->cl->decreaseHealth(this->cl->getStrength());
    if (this->closestEnemy->cl->getHealth() <= 0) {
        delete this->closestEnemy;
    }
}

Vector2 Unit::calculateNextPosition() {
    Vector2 result = this->position;
    if (this->closestEnemy) {
        double direction = this->position.getDirection(this->closestEnemy->position);
        std::cout << direction << std::endl; // to be removed
        if (-3.14 <= direction && direction < -2.36)
            result.y--;
        else if (-2.36 <= direction && direction < -1.57)
            result.x--;
        else if (-1.57 <= direction && direction < -0.79)
            result.x--;
        else if (-0.79 <= direction && direction < 0)
            result.y++;
        else if (0 <= direction && direction < 0.79)
            result.y++;
        else if (0.79 <= direction && direction < 1.57)
            result.x++;
        else if (1.57 <= direction && direction < 2.36)
            result.x++;
        else if (2.36 <= direction && direction < 3.14)
            result.y--;
    }
    return result;
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
    if (!units.empty()) {
        Unit *result;
        Vector2 corner1(0, 0);
        Vector2 corner2(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
        int distance = corner1.getDistanceToPoint(corner2);
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
        this->closestEnemy = nullptr; // if there are no enemies // TODO check if its necessery
    }
}

//Unit* Unit::getClosestUnit(int team) {
//  
//}
