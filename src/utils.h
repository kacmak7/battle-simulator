#ifndef UTILS_H
#define UTILS_H

#include <math.h>

struct Vector2 {
    int x, y;

    Vector2() :
        x(0), y(0)
    {}

    Vector2(int x, int y) :
        x(x), y(y)
    {}

    int getDistanceToPoint(Vector2 point) {
        return sqrt((x-y)^2 + (point.x-point.y)^2);
    }
};

#endif