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

private:
    LocationChunk location_data[10][10];
};

} // namespace rpback

#endif // LOCATION_H
