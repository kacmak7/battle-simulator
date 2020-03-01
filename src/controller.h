#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"
#include "class.h"

/*
 * Purpose of this class is to control the gameplay, somewhat like a menu, control panel
 */

class Controller {
public:
    Controller();
    ~Controller();

    // Generates and deploys units to the battlefield
    // void deployUnits(int numberOfUnits);

    /*
     * The only event listener, tracks and process mouse and keyboard signals
     */
     void process();


private:
    
    /*
     * User defined variable what team to deploy
     */
    int team;

    /*
     * User defined variable what class to deploy
     * Currently there is no possibility to define your class,
     * user needs to stick with predefined options 1, 2, 3, 4
     */
    Class* cl;

    void exit();
};

#endif