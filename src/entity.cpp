#include "entity.h"
#include "location.h"
using namespace rpback;

Entity::Entity(Location *location, Coord x, Coord y)
    : position_x(x), position_y(y)
{}

void Entity::teleportTo(Coord x, Coord y)
{

}
