#include "location.h"
using namespace std;
using namespace rpback;

Location::Schema Location::schema;

void Location::resize(Coord minx, Coord miny, Coord maxx, Coord maxy)
{
    location_data.clear();

    min_x = minx;
    min_y = miny;
    max_x = maxx;
    max_y = maxy;
}
