#include "unit.h"
#include "graphics.h"

Unit::Unit(int x, int y, int team, Graphics* graphics) {
    this->id = Unit::currentId++;
    Unit::units[id] = this;
    this->position.x = x;
    this->position.y = y;
    this->team = team;
    this->graphics = graphics;
    this->graphics->drawPoint(this->position);
}

Unit::~Unit() {
    this->graphics->erasePoint(this->position);
    Unit::units.erase(this->id); // TODO: consider if it's better to null an object in Unit::units
}

int Unit::currentId = 0;

std::map<int, Unit*> Unit::units;

void Unit::action() {
    if (isNextToEnemy()) {
        attack();
    } else {
        move();
    }
}

void Unit::move() {
    Vector2 nextPosition = this->calculateNextPosition();
    if (canMove(nextPosition)) {
        this->position = nextPosition;
        this->graphics->erasePoint(this->position);
        //this->graphics->setDrawColor();
        this->graphics->drawPoint(this->position);
    }
}

void Unit::attack() {

}

Vector2 Unit::calculateNextPosition() {
    // TODO
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
    this->assignClosestEnemy(); // TODO: optimization
    if (this->closestEnemy) {

    }
}

void* Unit::assignClosestEnemy() {
    // TODO: pack it in generic method to not to repeat the same code in canMove()
    if (!units.empty()) {
        Unit *result;
        int distance;
        if (Graphics::SCREEN_WIDTH >= Graphics::SCREEN_HEIGHT) {
            distance = Graphics::SCREEN_WIDTH;
        } else {
            distance = Graphics::SCREEN_HEIGHT;
        }
        for (int i = 0; i < Unit::currentId; i++) {
            if (units.find(i) != units.end()) { // check if current unit is still alive
                Unit *u = units.at(i);
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
    }
    this->closestEnemy = nullptr;
}

Unit* Unit::getClosestUnit(int team) {

}
