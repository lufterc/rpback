#include <iostream>
#include <micropather/micropather.h>
#include "world.h"
using namespace std;

namespace rpback {

class Game
{
public: void processEvents() {}
public: void loadResources() {}

private:
    World world;
};

class InputProcessor
{
public: void processInput() {}
};

} // namespace rpback

#ifdef RPBACK_NO_MAIN
int rpback_main()
#else
int main()
#endif
{
    rpback::Game game;
    rpback::InputProcessor input;

    game.loadResources();

    while (true)
    {
        game.processEvents();
        input.processInput();
    }
    return 0;
}
