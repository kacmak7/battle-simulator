#ifndef CLASS_H
#define CLASS_H

#include "utils.h"

class Class {
public:
    Class(int health, int strength, Rgb color);
    ~Class();

    void decreaseHealth(int value);

    int getHealth();

    int getStrength();
    
    Rgb getColor();

private:
    /*
     * Points of endurance. The more, the longer unit will last
     */
    int health;

    /*
     * Points of attack strength. The more, the bigger damage to opponents unit will provide
     */
    int strength;

    /*
     * Specifies what color Unit of that class should wear
     */
    Rgb color;
};

#endif
