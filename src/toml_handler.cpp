#include "toml_handler.h"
#include "data_manager.h"
using namespace rpback;
using namespace std;

map<string, TomlHandler::SpecialCall> TomlHandler::special =
{
    { "@include", &TomlHandler::include_proto },
    { "@refid",   &TomlHandler::include_proto },
    { "@norefid", &TomlHandler::include_proto }
};

void TomlHandler::include_proto(const std::string& id)
{
    // we need datamanager here...
    dm.fillNode(interface(), id.c_str());
}
