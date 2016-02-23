#include "catch/catch.hpp"
#include "settings.h"
using namespace rpback;
using namespace std;

TEST_CASE("Argc/argv parser test", "[argv]")
{
    Settings settings;
    REQUIRE( settings.dataDir() == "./data" );

    int argc = 3;
    const char *argv[] = { ".",
                           "--data-dir", "mydata" };

    settings.parse(argc, argv);
    REQUIRE( settings.dataDir() == "mydata" );
}
