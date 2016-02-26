#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include "world.h"
#include "data_manager.h"

namespace rpback
{

class Game
{
public:
    Game(DataManager &data_manager)
        : dm(data_manager)
    {}

    void newGame();
    void saveGame(const char *savegame);
    void loadGame(const char *savegame);
    void processInput();

private:
    Owner<World> world;
    DataManager &dm;
};

} // namespace rpback

#endif // GAME_H_
