#include "controller.h"
#include "unit.h"

Controller::Controller() {}
Controller::~Controller() {}

void Controller::deployUnits(int numberOfUnits, Vector2 pos, int type) {
    switch (type) {
        case 1: deployOptimally(numberOfUnits, pos);
            break;
        case 2: deployRandomly(numberOfUnits, pos);
            break;
        default: deployOptimally(numberOfUnits, pos);
            break;
    }
}

void Controller::deployOptimally(int numberOfUnits, Vector2 pos) {

}

void Controller::deployRandomly(int numberOfUnits, Vector2 pos) {

}
