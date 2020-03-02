#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "utils.h"
#include "class.h"

/*
 * Controls the gameplay, somewhat like a menu, control panel
 */
class Controller {
public:
    Controller();
    ~Controller();

    /*
     * The only event listener, tracks and process mouse and keyboard signals
     */
    void process();

private:

    SDL_Event event;

    /*
     * User defined variable what team to deploy
     * Up to 10 teams - numbers from 0 to 9
     */
    int team;

    /*
     * User defined variable what class to deploy TODO
     * Currently there is no possibility to define your class,
     * user needs to stick with predefined options
     */
    Class* cl;

    void setTeam();

    void setClass();
    
    /*
     * Generates and deploys units to the battlefield
     */ 
    void deployUnits(int numberOfUnits);

    void exit();
};

#endif