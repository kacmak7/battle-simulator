#ifndef UTILS_H
#define UTILS_H

#include <math.h>

namespace Utils {
    float round2dec(float f);
}

struct Vector2 {
    int x, y;

    Vector2() :
    x(0), y(0)
    {}

    Vector2(int x, int y) :
    x(x), y(y)
    {}

    bool operator==(const Vector2& v) {
        if (this->x == v.x && this->y == v.y) {
            return true;
        } else {
            return false;
        }
    }

    float getDistanceToPoint(Vector2 v) {
        return Utils::round2dec(sqrt(pow(x - v.x, 2) + pow(y - v.y, 2)));
    }
};

#endif