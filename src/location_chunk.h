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

//    inline std::weak_ptr<Body> entity(Id id);

private:
    OccupancyGrid occupancy_grid;
//    Index<std::shared_ptr<Body>> entity_index;

private:
    static const size_t CHUNK_SIZE = 10;
};

//std::weak_ptr<Body> LocationChunk::entity(Id id)
//{
//    return entity_index[id];
//}

} // namespace rpback

#endif // RPBACK_MAP_CHUNK_H
