#ifndef WORLD_H
#define WORLD_H

#include <map>
#include "main.h"
#include "schema_types.h"
#include "location.h"

namespace rpback
{

class DataManager;

class World
{
public:
    void tick(); // time passes...

    void init(DataManager &dm);

    void *content(const char *) { return nullptr; }

public:
    Duration time() const { return world_time; }
private:
    Duration world_time = 0;

public:
    Duration phaseDuration() const { return phase_duration; }
private:
    Duration phase_duration = 0;

public:
    Duration phaseOvertime() const { return phase_overtime; }
private:
    Duration phase_overtime = 0;

private:
    Owner<Location> current_location;

private:
    friend class SchemaInstance<World>;
    static struct Schema : public SchemaMap<World>
    {
        Schema()
        {
            persistent<SchemaDuration>("phase_duration", &World::phase_duration);
            persistent<SchemaDuration>("phase_overtime", &World::phase_overtime);
            dynamic<SchemaDuration>("world_time", &World::world_time);

            // table("object") -> create new Entity, fill new Entity,
            // location->add(Entity) - all new keys should go to "new entity",
            // and on "finish_table" new entity added to location

            // no need for string name - component should have string name
            // as class member
            //add<SchemaComponent<WeaponComponent>>(&World::component_list);
        }
    }
    schema;
};

} // namespace rpback

#endif // WORLD_H
