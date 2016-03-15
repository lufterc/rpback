#include <sstream>
#include "catch/catch.hpp"
#include "loltoml/parse.hpp"
#include "game.h"
#include "world.h"
#include "location.h"
#include "toml_handler.h"
#include "data_manager.h"
using namespace std;
using namespace rpback;

#define EOL "\n"

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
    data_manager.fill(world, "world_settings");
    REQUIRE( world.phaseDuration() == 300 );
    REQUIRE( world.phaseOvertime() == 100 );

    Location location;
    string test_level =
            "max_x = 100"  EOL
            "max_y = 100"  EOL
            "min_x = -100" EOL
            "min_y = -100" EOL
            ""             EOL
            "[[object]]"    EOL
            "pos_x = 15"
            "pos_y = 20"
            EOL;

    stringstream ss(test_level);
    SchemaInstance<Location> schema(location);
    TomlHandler handler(schema, data_manager);
    loltoml::parse(ss, handler);
    REQUIRE( location.maxX() == 100 );
}
