#ifndef UNIT_H
#define UNIT_H

struct Position {
    int x, y;
};

class Unit {
public:
    Unit();
    ~Unit();
private:
    Position* position;
};

#endif
