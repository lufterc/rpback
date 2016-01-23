#ifndef RPBACK_MAP_CHUNK_H
#define RPBACK_MAP_CHUNK_H

#include <list>
#include "occupancy_grid.h"

namespace rpback {

class ItemFunction;
class Entity
{
public:
    virtual void accept(ItemFunction *) {}
};

class LocationChunk
{
public:
    LocationChunk();

private:
    OccupancyGrid occupancy_grid;
    std::list<std::unique_ptr<Entity>> object_list;
};

} // namespace rpback

#endif // RPBACK_MAP_CHUNK_H
