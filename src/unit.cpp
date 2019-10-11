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
    Unit::units.erase(this->id);
}

int Unit::currentId = 0;

std::map<int, Unit*> Unit::units;

void Unit::move() {
    this->graphics->erasePoint(this->position);
    this->position = this->getNextPosition();
    //this->graphics->setDrawColor();
    this->graphics->drawPoint(this->position);
}

Position Unit::getNextPosition() {

}

Unit Unit::getClosestEnemy() {
    for (int i = 0; i < Unit::currentId; i++) {
        Unit u = unit.find(i);
        if (u != units.end()) {
            if (u.team != this->team) {

            }
        }
    }
}
