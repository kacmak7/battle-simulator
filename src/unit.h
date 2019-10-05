#ifndef UNIT_H
#define UNIT_H

class Unit {
public:
    Unit(int x, int y, int team);
    ~Unit();

private:
    int x; // position
    int y; // position
    int team;


};

#endif
//TODO: feature bug: covering of the units