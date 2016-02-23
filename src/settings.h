#ifndef _RPBACK_SETTINGS_H_
#define _RPBACK_SETTINGS_H_

#include <string>

namespace rpback
{

/**
 * @brief The Settings class stores values from argc/argv, environment variables
 *        and config files and makes them available to everyone
 */
class Settings
{
public:
    Settings();
    void parse(int argc, const char * const argv[]);

public:
    const std::string& dataDir() const { return data_dir; }
private:
    std::string data_dir = "./data";
};

} // namespace rpback

#endif // _RPBACK_SETTINGS_H_
