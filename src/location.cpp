#include "location.h"
using namespace std;
using namespace rpback;

Location::Schema Location::schema;

void Location::resize(Coord tx, Coord ty, Coord bx, Coord by)
{
    location_data.clear();

    top_x = tx;
    top_y = ty;
    bottom_x = bx;
    bottom_y = by;
}
