#ifndef WORLD_H
#define WORLD_H

#include <map>
#include "main.h"
#include "schema_types.h"
#include "location.h"

namespace rpback
{

class World
{
public:
    void tick(); // time passes...

    void changeLocation(std::unique_ptr<Location>);

public:
    Time time() const { return world_time; }
private:
    Time world_time = 0;

public:
    Duration phaseDuration() const { return phase_duration; }
private:
    Duration phase_duration = 0;

public:
    Duration phaseOvertime() const { return phase_overtime; }
private:
    Duration phase_overtime = 0;

private:
    std::unique_ptr<Location> current_location;

private:
    friend class DataManager;
    static struct Schema : public SchemaMap<World>
    {
        Schema()
        {
            add<SchemaDuration>("phase_duration", &World::phase_duration);
            add<SchemaDuration>("phase_overtime", &World::phase_overtime);
        }
    }
    schema;
};

} // namespace rpback

#endif // WORLD_H
