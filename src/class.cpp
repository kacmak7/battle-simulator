#include "class.h"
#include "utils.h"

Class::Class() {
    // temporary test
    Rgb testRgb(10,42,12);
    this->color = testRgb;
}

Class::~Class() {}

Rgb Class::getColor() {
    return this->color;
}
