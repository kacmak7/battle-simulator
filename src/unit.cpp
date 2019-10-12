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

// TODO: optimize it
Unit* Unit::getClosestEnemy() {
    if (!units.empty()) {
        Unit *result;
        int distance;
        if (Graphics::SCREEN_WIDTH >= Graphics::SCREEN_HEIGHT) {
            distance = Graphics::SCREEN_WIDTH;
        } else {
            distance = Graphics::SCREEN_HEIGHT;
        }
        for (int i = 0; i < Unit::currentId; i++) {
            if (units.find(i) != units.end()) { // check if unit is still alive
                Unit *u = units.at(i);
                if (u->team != this->team) { // omit friendly units
                    int tempDistance = position.getDistanceToPoint(u->position);
                    if (tempDistance < distance) {
                        distance = tempDistance;
                        result = u;
                    }
                }
            }
        }
        return result;
    }
    return nullptr;
}
