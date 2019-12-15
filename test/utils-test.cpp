#define CATCH_CONFIG_MAIN

#include "../lib/catch.hpp"
#include "../src/utils.h"

TEST_CASE("getDistanceToPoint-test") {
    Vector2 p1(0,0);
    Vector2 p2(21,43);
    Vector2 p3(5,82);
    Vector2 p4(124,821);
    Vector2 p5(4212,8532);
    Vector2 p6(11544,24512);

    REQUIRE(p1.getDistanceToPoint(p2) == (float)47.85);
    REQUIRE(p4.getDistanceToPoint(p2) == (float)784.79);
    REQUIRE(p3.getDistanceToPoint(p5) == (float)9439.35);
    REQUIRE(p5.getDistanceToPoint(p6) == (float)17581.77);
}

TEST_CASE("isNeighbor-test") {
    Vector2 p1(23,53);
    Vector2 p2(24,54);
    Vector2 p3(143,120);
    Vector2 p4(142,120);

    REQUIRE(p1.isNeighbor(p2) == true);
    REQUIRE(p3.isNeighbor(p4) == true);
    REQUIRE(p4.isNeighbor(p4) == false);
}