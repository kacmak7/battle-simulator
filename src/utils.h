#ifndef UTILS_H
#define UTILS_H

#include <math.h>

namespace Utils {
    float round2dec(float f);
}

struct Vector2 { // TODO move this struct to the source file
    int x, y;

    Vector2() :
    x(0), y(0)
    {}

    Vector2(int x, int y) :
    x(x), y(y)
    {}

    bool operator == (const Vector2& v) {
        if (this->x == v.x && this->y == v.y) {
            return true;
        } else {
            return false;
        }
    }

    float getDistanceToPoint(Vector2 v) {
        return Utils::round2dec(sqrt(pow(x - v.x, 2) + pow(y - v.y, 2)));
    }

    bool isNeighbor(Vector2 v) {
        int param1 = abs(x - v.x);
        int param2 = abs(y - v.y);
        if ((param1 == 0 || param1 == 1) && (param2 == 0 || param2 == 1) &&
            (param1 == 1 || param2 == 1)) {
            return true;
        }
        else {
            return false;
        }
    }
};

struct Rgb { // TODO move this too
    int red, green, blue;

    Rgb(int r, int g, int b) :
    red(r), green(g), blue(b)
    {}

    bool operator == (const Rgb& rgb) {
        if (this->red == rgb.red && this->blue == rgb.blue && this->green ==rgb.green) {
            return true;
        } else {
            return false;
        }
    }
};

#endif