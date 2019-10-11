#include "unit.h"
#include "graphics.h"

Unit::Unit(int x, int y, int team, Graphics* graphics) {
    this->id = currentId++;
    units[id] = this;
    this->position.x = x;
    this->position.y = y;
    this->team = team;
    this->graphics = graphics;
    this->graphics->drawPoint(this->position);
}

Unit::~Unit() {
    this->graphics->erasePoint(this->position);
    units.erase(this->id);
}

void Unit::move() {
    this->graphics->erasePoint(this->position);
    this->position = this->getNextPosition();
    //this->graphics->setDrawColor();
    this->graphics->drawPoint(this->position);
}

Position Unit::getNextPosition() {

}

Unit Unit::getClosestEnemy() {

}
