#include "world.h"

namespace rpback
{

void World::changeLocation(Location *new_location)
{
    current_location.reset(new_location);
}

} // namespace rpback
