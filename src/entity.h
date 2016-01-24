#ifndef ENTITY_H
#define ENTITY_H

#include "main.h"

namespace rpback
{

class ItemFunction;
class Controller;
class Entity
{
public:
    Entity(Coord x, Coord y)
        : position_x(x), position_y(y)
    {}

    virtual void accept(ItemFunction *) {}
    void teleportTo(Coord x, Coord y);

    Coord x() const { return position_x; }
    Coord y() const { return position_y; }

private:
    Coord position_x;
    Coord position_y;
    std::weak_ptr<Controller> controller;
};

// class StaticEntity
// class DynamicEntity

} // namespace rpback

#endif // ENTITY_H
