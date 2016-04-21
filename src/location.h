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

    void resize(Coord minx, Coord miny, Coord maxx, Coord maxy);

    // state: staying, sitting, laying

    //
    // add - insert item in one of collections
    // add("item")
    // add("injury")
    //

#if 0
    dm.staticFill(location, "maps/location_map");
    if (!visited) dm.stateFill(location, "maps/location_map.state");
    else dm.savedFill(location, "maps/location_map.state");
#endif

#if 0
    child *getChild(uuid), if uuid == 0 -> new child
    map location_index
#endif

public:
    Coord minX() const { return min_x; }
    Coord minY() const { return min_y; }
    Coord maxX() const { return max_x; }
    Coord maxY() const { return max_y; }

private:
    Coord min_x = 0;
    Coord min_y = 0;
    Coord max_x = 0;
    Coord max_y = 0;

    // switch to location: current_location->serialize(); current_location = goto_location
    // cutscene: save current location name to var; change location, play scene,
    // change locatoin back

#if 0
    String prototype_id;
    Array[] surface = "......";
    Flag persistent = true;
#endif

    // mechanisms: it's not loaded during init, but only after that
    OwnerContainer<Entity> location_data;
    IndexMap<Entity> index_map;

#if 0
    World &world;
#endif

private:
    friend class SchemaInstance<Location>;
    Owner<SchemaInterface> component(const std::string &id)
    {
        // check index, in case there is already object with id
        Id new_id = std::stoull(id, nullptr, 16); // catch exception!
        auto result = index_map.find(new_id);
        if (result == index_map.end())
        {
            location_data.push_back(new Entity());
            index_map[new_id] = location_data.back().get();
            return Owner<SchemaInterface>
                    (new SchemaInstance<Entity>(*location_data.back()));
        }

        return Owner<SchemaInterface>
                (new SchemaInstance<Entity>(*result->second));
    }

    static struct Schema : public SchemaMap<Location>
    {
        Schema()
        {
#if 0
            dynamic<SchemaString>("_proto", &Location::prototype_id);
#endif
            persistent<SchemaCoord>("min_x", &Location::min_x);
            persistent<SchemaCoord>("min_y", &Location::min_y);
            persistent<SchemaCoord>("max_x", &Location::max_x);
            persistent<SchemaCoord>("max_y", &Location::max_y);
            component<Entity>("object", &Location::component);
        }
    }
    schema;
};

} // namespace rpback

#endif // LOCATION_H
