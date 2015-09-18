#ifndef RPBACK_MAP_CHUNK_H
#define RPBACK_MAP_CHUNK_H

#include <cstdint>
#include <list>

namespace rpback {

template <typename Map>
class MapChunk
{
public:
    MapChunk();

private:
    MapChunk<Map>
    *left = nullptr,
    *right = nullptr,
    *top = nullptr,
    *bottom = nullptr,
    *up = nullptr,
    *down = nullptr;

    std::int8_t *occupancy_grid;
    std::int8_t *objects_list;
};

} // namespace rpback

#endif // RPBACK_MAP_CHUNK_H
