#ifndef RPBACK_MAP_CHUNK_H
#define RPBACK_MAP_CHUNK_H

#include <list>
#include "entity.h"
#include "index.h"
#include "occupancy_grid.h"

namespace rpback {

class LocationChunk
{
public:
    LocationChunk();
    static size_t size() { return CHUNK_SIZE; }

#if 0
    inline std::weak_ptr<Body> entity(Id id);
#endif

private:
    OccupancyGrid occupancy_grid;

#if 0
    Index<std::shared_ptr<Body>> entity_index;
#endif

private:
    static const size_t CHUNK_SIZE = 10;
};

#if 0
    std::weak_ptr<Body> LocationChunk::entity(Id id)
    {
        return entity_index[id];
    }
#endif

} // namespace rpback

#endif // RPBACK_MAP_CHUNK_H
