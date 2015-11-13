#ifndef RPBACK_MAP_CHUNK_H
#define RPBACK_MAP_CHUNK_H

#include <cstdint>
#include <vector>
#include <list>

#include "occupancy_grid.h"

namespace rpback {

class MapChunk
{
public: /// METHODS
    MapChunk();

private: /// VARS
    OccupancyGrid occupancy_grid;
};

} // namespace rpback

#endif // RPBACK_MAP_CHUNK_H
