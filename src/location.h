#ifndef LOCATION_H
#define LOCATION_H

#include "main.h"
#include "schema_types.h"
#include "location_chunk.h"

namespace rpback {

class Body;


class Location
{
public:
    void add(Entity *);
    Entity* entity(Id uuid);

    void resize(Coord tx, Coord ty, Coord bx, Coord by);

    // state: staying, sitting, laying

    //
    // add - insert item in one of collections
    // add("item")
    // add("injury")
    //

    // dm.staticFill(location, "maps/location_map");
    // if (!visited) dm.stateFill(location, "maps/location_map.state");
    // else dm.savedFill(location, "maps/location_map.state");

    // child *getChild(uuid), if uuid == 0 -> new child
    // map location_index

private:
    Coord top_x = 0;
    Coord top_y = 0;
    Coord bottom_x = 0;
    Coord bottom_y = 0;
    // Array[] surface = "fdsfadsfaf";

    //    Flag persistent = true;

    // mechanisms: it's not loaded during init, but only after that
    OwnerContainer<Entity> location_data;

private:
    Owner<SchemaInterface> component(const std::string &id)
    {
        location_data.push_back(new Entity());
        return Owner<SchemaInterface>(new SchemaInstance<Entity>(*location_data.back()));
    }

    friend class SchemaInstance<Location>;
    static struct Schema : public SchemaMap<Location>
    {
        Schema()
        {
            persistent<SchemaCoord>("top_x", &Location::top_x);
            persistent<SchemaCoord>("top_y", &Location::top_y);
            persistent<SchemaCoord>("bottom_x", &Location::bottom_x);
            persistent<SchemaCoord>("bottom_y", &Location::bottom_y);
            component<Entity>("object", &Location::component);
        }
    }
    schema;
};

} // namespace rpback

#endif // LOCATION_H
