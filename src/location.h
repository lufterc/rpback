#ifndef LOCATION_H
#define LOCATION_H

#include "main.h"
#include "location_chunk.h"

namespace rpback {

class Entity;
class Location
{
public:
    void addEntitiy(Entity *);
    void loadMap(); // from file

    void resize(Coord tx, Coord ty, Coord bx, Coord by);

private:
    Coord top_x = 0;
    Coord top_y = 0;
    Coord bottom_x = 0;
    Coord bottom_y = 0;
    std::vector<std::unique_ptr<LocationChunk>> location_data;
};

} // namespace rpback

#endif // LOCATION_H
