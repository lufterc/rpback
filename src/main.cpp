#include <iostream>
#include <micropather/micropather.h>
using namespace std;

namespace rpback {

class Game
{
public: void processEvents() {}
public: void loadResources() {}
};

class InputProcessor
{
public: void processInput() {}
};

// Useful links:
// https://www.wpsoftware.net/andrew/pages/libyaml.html

} // namespace rpback

int main()
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
