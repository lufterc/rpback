#include "catch/catch.hpp"
#include "world.h"
#include "location.h"
#include "data_manager.h"
#include "game.h"
using namespace std;
using namespace rpback;

TEST_CASE("This is a sample test", "[sample]")
{
    REQUIRE( 2 + 2 == 4 );
}

TEST_CASE("Basic world test", "[world]")
{
    Settings settings;
    DataManager data_manager(settings);
    Game game(data_manager);

    World world;
    data_manager.fill(&world, "world_settings");
    REQUIRE( world.phaseDuration() == 10 );

//    World world;
//    REQUIRE(world.time() == 0);

//    world.init(dm);

//    Location area;
//    area.resize(-100, -100, 100, 100);

//    int a, b, c, d;
//    serial(a, b, c, d, a, d, c);

//    SerialMap<int> smap = { {
//        { "value", [](int) { return true; } },
//        { "value2", [](int) { return false; } }
//    } };

//    Entity *person = new Entity(area.get(), 10, 10);

}
