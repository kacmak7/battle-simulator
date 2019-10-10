#include "unit.h"
#include "graphics.h"

Unit::Unit(int x, int y, int team, Graphics* graphics) {
    this->x = x;
    this->y = y;
    this->team = team;
    this->graphics = graphics;
    this->graphics->drawPoint(this->x, this->y);
}

Unit::~Unit() {}