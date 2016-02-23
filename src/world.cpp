#include "world.h"
#include "data_manager.h"
using namespace std;
using namespace rpback;

World::Schema World::schema;

void World::changeLocation(std::unique_ptr<Location> new_location)
{
    current_location = move(new_location);
}

#if 0
void World::init(DataManager &dm)
{
    auto ac = dm.loadProto("game_settings");
}
#endif
