#ifndef RPBACK_MAP_CHUNK_H
#define RPBACK_MAP_CHUNK_H

#include <list>
#include "entity.h"
#include "occupancy_grid.h"

namespace rpback {

class LocationChunk
{
public:
    LocationChunk();

private:
    OccupancyGrid occupancy_grid;
    std::list<std::unique_ptr<Entity>> object_list;
    // object_index
};

} // namespace rpback

#endif // RPBACK_MAP_CHUNK_H
