#ifndef ENTITY_H
#define ENTITY_H

#include "main.h"

namespace rpback
{

class ItemFunction;
class Controller;
class Location;

class Entity
{
public:
    Entity(Location *location, Coord x, Coord y);
    virtual void accept(ItemFunction *) {}
    void teleportTo(Coord x, Coord y);

    Coord x() const { return position_x; }
    Coord y() const { return position_y; }

private:
    Id chunk_id;
    Coord position_x;
    Coord position_y;
    std::weak_ptr<Controller> controller;
};

// class StaticEntity
// class DynamicEntity

// class Door
// class Person

} // namespace rpback

#endif // ENTITY_H
