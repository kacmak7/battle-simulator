#include "unit.h"
#include "graphics.h"

Unit::Unit(int x, int y, int team, Graphics* graphics) {
    this->position.x = x;
    this->position.y = y;
    this->team = team;
    this->graphics = graphics;
    this->graphics->drawPoint(this->position);
}

Unit::~Unit() {}

void Unit::move() {
    this->graphics->erasePoint(this->position);

}

Position Unit::getNextPosition() {

}

Unit Unit::getClosestEnemy() {

}
