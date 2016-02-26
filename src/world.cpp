#include "world.h"
#include "data_manager.h"
using namespace std;
using namespace rpback;

World::Schema World::schema;

void World::init(DataManager &dm)
{
    String location_id = "maps/sample_map";
    current_location.reset(new Location());
    dm.fill<Location>(*current_location, location_id.c_str());
}

#if 0
void World::changeLocation(std::unique_ptr<Location> new_location)
{
    current_location = move(new_location);
}
#endif

#if 0
void World::init(DataManager &dm)
{
    auto ac = dm.loadProto("game_settings");
}
#endif
