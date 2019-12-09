#include "controller.h"
#include "unit.h"

Controller::Controller() {}
Controller::~Controller() {}

void Controller::deployUnits(int numberOfUnits, Vector2 pos, int type) {
    switch (type) {
        case 1: deployOptimal(numberOfUnits, pos);
            break;
        case 2: deployRandomly(numberOfUnits, pos);
        default: deployOptimal;
            break;
    }
}

void Controller