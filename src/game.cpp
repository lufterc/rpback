#include "game.h"
using namespace std;
using namespace rpback;

void Game::newGame()
{
    // reset game...
    world.reset(new World());

    // init from toml file
    dm.fill<World>(*world, "world_settings");

    // change location to starting location
}

void Game::loadGame(const char *savegame)
{
    // reset game...

    // init from toml file
    // fill values from kv storage
}

void Game::processInput()
{

}
