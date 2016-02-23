#include "settings.h"
#include <cstring>
using namespace std;
using namespace rpback;

Settings::Settings()
{
}

void Settings::parse(int argc, const char * const argv[])
{
    int arg = 1;
    while (arg < argc)
    {
        if (0 == strcmp(argv[arg], "--data-dir"))
        {
            ++arg;
            if (arg > argc)
            {
                break;
            }
            data_dir = argv[arg];
        }

        else if (false)
        {

        }

        ++arg;
    }
}
