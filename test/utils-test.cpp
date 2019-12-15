#define CATCH_CONFIG_MAIN

#include "../lib/catch.hpp"
#include "../src/utils.h"

// for each SECTION the TEST_CASE is executed from the beginning

TEST_CASE("Distances between points") {
    Vector2 p1(0,0);
    Vector2 p2(21,43);
    Vector2 p3(5,82);
    Vector2 p4(124,821);
    Vector2 p5(4212,8532);

    REQUIRE(p1.getDistanceToPoint(p2) == 47.85);
    REQUIRE(p4.getDistanceToPoint(p2) == 2.3);
}