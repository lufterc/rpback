#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include <fstream>
#include "main.h"
#include "settings.h"
#include "schema_types.h"
#include "toml_handler.h"
#include "loltoml/parse.hpp"

namespace rpback
{

class DataManager;

/**
 * @brief The DataManager class provides abstract key-value storage for other
 *        classes
 */
class DataManager
{
public:
    DataManager(Settings &_settings)
        : settings(_settings)
    {}

    template <typename Structure>
    inline void fill(Structure& structure, const char *resource_id);

    inline void fillNode(SchemaInterface& schema, const char *resource_id);

    template <typename Structure>
    void save(Structure& structure, std::string& output)
    {
    }

private:
    Settings& settings;
};

void DataManager::fillNode(SchemaInterface& schema, const char *resource_id)
{
    std::ifstream file(settings.dataDir() + "/" + resource_id + ".toml");
    TomlHandler handler(schema, *this);

    loltoml::parse(file, handler);
}

template <typename Structure>
void DataManager::fill(Structure &structure, const char *resource_id)
{
    SchemaInstance<Structure> schema(structure);
    fillNode(schema, resource_id);
}

} // namespace rpback

#endif // _DATA_MANAGER_H_
