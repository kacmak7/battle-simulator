#ifndef UTILS_H
#define UTILS_H

struct Position {
    int x, y;
    Position() :
        x(0), y(0)
    {}
    Position(int x, int y) :
        x(x), y(y)
    {}
};

#endif