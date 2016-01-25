#include <catch/catch.hpp>
#include "world.h"
#include "location.h"
using namespace std;
using namespace rpback;

TEST_CASE("This is a sample test", "[sample]")
{
    REQUIRE( 2 + 2 == 4 );
}

TEST_CASE("Basic world test", "[world]")
{
    World world;
    REQUIRE(world.time() == 0);



//    unique_ptr<Location> area(new Location());

//    Entity *person = new Entity(area.get(), 10, 10);

}
