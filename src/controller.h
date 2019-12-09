#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"

class Controller {
public:
    Controller();
    ~Controller();

    //TODO: make a method generating units on the field near given position
    //TODO: implement logic of units deployment (exact initial place of every unit assuming they're circles)

    // Generates and deploys units to battle field
    void deployUnits(int numberOfUnits, Vector2 pos);

private:
    // Algorithms of units deployment
    void deployOptimally(int numberOfUnits, Vector2 pos);
    void deployRandomly(int numberOfUnits, pos);
};
//TODO: pointers ;)

#endif