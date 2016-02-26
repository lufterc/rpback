#include "entity.h"
#include "location.h"
using namespace rpback;

Entity::Schema Entity::schema;

Body::Body(Location *location, Coord x, Coord y)
    : position_x(x), position_y(y)
{}

void Body::teleportTo(Coord x, Coord y)
{

}
