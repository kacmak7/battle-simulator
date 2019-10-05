#ifndef UNIT_H
#define UNIT_H

class Unit {
public:
    Unit(int x_pos, int y_pos) {
        x = x_pos;
        y = y_pos;
    }
    ~Unit();
private:
    int x; // position
    int y; // position

//TODO: to define how to bind animation to object

};

#endif
