#ifndef ITEM_FUNCTION_H
#define ITEM_FUNCTION_H

#include <string>
#include "main.h"

namespace rpback {

class Creature;
class Door;

class ItemFunction
{
public:
    StringID name() const { return fun_name; }

    virtual bool check(Creature *) { return false; }
    virtual void visit(Creature *) {}

    virtual bool check(Door *) { return false; }
    virtual void visit(Door *) {}

private:
    StringID fun_name = 0;
};

// class Open
// class Close
// class Crack
// class Jam

} // namespace rpback

#endif // ITEM_FUNCTION_H
