#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"

TEST_CASE("This is a sample test", "[sample]")
{
    REQUIRE( 2 + 2 == 4 );
}
