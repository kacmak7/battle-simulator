#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"

/*
 * Purpose of this class is to control the gameplay, somewhat like a menu, control panel
 */

class Controller {
public:
    Controller();
    ~Controller();

    // Generates and deploys units to the battlefield
    void deployUnits(int numberOfUnits, Vector2 pos);

};

#endif