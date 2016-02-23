#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_

#include "main.h"
#include "settings.h"
#include "schema_types.h"
//#include "loltoml/parse.hpp"

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
    void fill(Structure *structure, const char *resource_id);

private:
    Settings& settings;
};

template <typename Structure>
void DataManager::fill(Structure *structure, const char *resource_id)
{
    // open file via fstream
    // create handler instance
    // parse with loltoml
    //loltoml::parse();

    auto field = structure->schema.find("phase_duration");
    if (!field)
    {
        return;
    }

    field->accept(10, *structure);
}

} // namespace rpback

#endif // DATA_MANAGER_H_
