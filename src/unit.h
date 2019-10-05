#ifndef UNIT_H
#define UNIT_H

class Unit {
public:
    Unit(int xPos, int yPos, int side);
    ~Unit();
private:
    int x; // position
    int y; // position
    int side;

//TODO: to define how to bind animation to object

};

#endif
