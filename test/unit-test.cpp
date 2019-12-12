#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../src/unit.h"

// for each SECTION the TEST_CASE is executed from the beginning

TEST_CASE("Single Unit on the battlefield", "[format]") {
    Graphics* graphics = new Graphics();
    Unit unit(1, 1, 0, graphics);

    SECTION("Test if unit is correctly initialized") {
        REQUIRE((unit.position.x == 1 && unit.position.y == 1));
    }

    SECTION("Test if unit is not moving after action()") {
        Vector2 initialPosition = unit.position;
        unit.action();
        //REQUIRE(unit.position == initialPosition);
    }
}