#include "utils.h"

float Utils::round2dec(float f) {
    float value = (int)(f * 100 + .5);
    return (float)value / 100;
}
