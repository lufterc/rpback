#ifndef WORLD_H
#define WORLD_H

#include "main.h"
#include "location.h"

namespace rpback
{

class World
{
public:
    Time time() const { return world_time; }
    void changeLocation(Location *);

private:
    Time world_time = 0;
    std::unique_ptr<Location> current_location;
};

} // namespace rpback

#endif // WORLD_H
