#include <catch/catch.hpp>
#include "world.h"

TEST_CASE("This is a sample test", "[sample]")
{
    REQUIRE( 2 + 2 == 4 );
}

TEST_CASE("Basic world test", "[world]")
{
    rpback::World world;
    REQUIRE(world.time() == 0);
}
