#ifndef UTILS_H
#define UTILS_H

#include <math.h>

struct Position { // TODO: rename to 'Point'
    int x, y;

    Position() :
        x(0), y(0)
    {}

    Position(int x, int y) :
        x(x), y(y)
    {}

    int getDistanceToPoint(Position p) {
        // sqrt((p1.x-p1.y)^2 + (p2.x-p2.y)^2)
    }
};

#endif