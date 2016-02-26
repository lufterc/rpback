#include <iostream>
#include "game.h"
#include "settings.h"
using namespace std;
using namespace rpback;

#include "micropather/micropather.h"

#ifdef RPBACK_NO_MAIN
int rpback_main(int argc, char **argv)
#else
int main(int argc, char **argv)
#endif
{
    Settings settings;
    settings.parse(argc, argv);

    DataManager dm(settings);

    Game game(dm);
    while (true)
    {
        game.processInput();
    }

    return 0;
}
