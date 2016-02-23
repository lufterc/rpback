#include <memory>
#include "catch/catch.hpp"
#include "index.h"
using namespace std;
using namespace rpback;

TEST_CASE("Basic index test", "[index]")
{
    Index<int> index;
    REQUIRE( index.count() == 0 );
    REQUIRE( index.reserved() == 0 );
    REQUIRE( index.free() == 0 );

    Id id = index.push_someplace(10);
    REQUIRE( index.count() == 1 );
    REQUIRE( index.reserved() == 1 );
    REQUIRE( index.free() == 0 );
    REQUIRE( id == 0 );
    REQUIRE( index[id] == 10 );

    for (int i = 0; i < 10; ++i)
    {
        index.push_someplace(i * 3 - 1);
    }
    REQUIRE( index.count() == 11 );
    REQUIRE( index.reserved() == 11 );
    REQUIRE( index.free() == 0 );
    REQUIRE( index[10] == 26 );

    index.pop_from(3);
    index.pop_from(5);
    index.pop_from(2);
    REQUIRE( index.count() == 8 );
    REQUIRE( index.reserved() == 11 );
    REQUIRE( index.free() == 3 );

    id = index.push_someplace(18);
    REQUIRE( id == 2 );
    REQUIRE( index.free() == 2 );
    REQUIRE( index[id] == 18 );
}

TEST_CASE("Reset and destruction checks", "[index]")
{
    int counter = 0;
    struct Bomb
    {
        Bomb(int &c) : counter(c) {}
        ~Bomb() { ++counter; }
        Bomb &operator=(const Bomb &other)
        {
            value = other.value;
        }

        int value = 10;
        int &counter;
        void reset() { value = -1; }
    };

    Index<Bomb> index;
    Id id = index.push_someplace(Bomb(counter));
    REQUIRE( id == 0 );
    REQUIRE( index.count() == 1 );
    REQUIRE( counter == 1 );

    index.pop_from(id);
    Bomb b = index[id];
    REQUIRE( b.value == -1 );
    REQUIRE( counter == 1 );

    Index<unique_ptr<Bomb>> pindex;
    unique_ptr<Bomb> bptr(new Bomb(counter));
    id = pindex.push_someplace(move(bptr));
    pindex.pop_from(id);
    REQUIRE( counter == 2 );
}
