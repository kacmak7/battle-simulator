#include "class.h"
#include "utils.h"

Class::Class(int health, int strength, Rgb color) {
    this->health = health;
    this->strength = strength;
    this->color = color;
}

Class::~Class() {}

void Class::decreaseHealth(int value) {
    this->health = this->health - value;
}

int Class::getHealth() {
    return this->health;
}

int Class::getStrength() {
    return this->strength;
}

Rgb Class::getColor() {
    return this->color;
}
