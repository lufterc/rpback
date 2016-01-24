#include "world.h"

namespace rpback
{

void World::changeLocation(std::unique_ptr<Location> new_location)
{
    current_location = move(new_location);
}

} // namespace rpback
