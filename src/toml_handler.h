#ifndef _TOML_HANDLER_H_
#define _TOML_HANDLER_H_

#include "schema_types.h"
#include "loltoml/parse.hpp"

namespace rpback
{

class DataManager;
class TomlHandler
{
public:
    TomlHandler(SchemaInterface& reference_schema,
                DataManager& reference_datamanager)
        : dm(reference_datamanager), root_schema(reference_schema)
    {}

    void start_document()
    {
    }

    void finish_document()
    {
    }

    void comment(const std::string &comment)
    {
        if (comment[0] == '@')
        {
            auto limit = comment.find(' ');
            auto call = special.find(comment.substr(0, limit));
            if (call == special.end())
            {
                ++parser_errors;
                return;
            }

            call->second(this, comment.substr(limit + 1));
        }
    }

    void key(const std::string &key)
    {
        if (!interface().key(key))
        {
            // throw?
            ++parser_errors;
        }
    }

    void string(const std::string &value)
    {
        if (!interface().string(value))
        {
            // throw?
            ++parser_errors;
        }
    }

    void boolean(bool value)
    {
        if (!interface().integer(value))
        {
            // throw?
            ++parser_errors;
        }
    }

    void integer(std::int64_t value)
    {
        if (!interface().integer(value))
        {
            // throw?
            ++parser_errors;
        }
    }

    void floating_point(double value)
    {
        if (!interface().real(value))
        {
            // throw?
            ++parser_errors;
        }
    }

    void datetime(const std::string &value)
    {
        // not supported
    }

    void table(loltoml::key_iterator_t begin, loltoml::key_iterator_t end)
    {
        for (auto i = begin; i != end; ++i)
        {
            component_schema = std::move(interface().component(*i, current_refid));
            if (!component_schema)
            {
                ++parser_errors;
                break;
            }
        }
    }

    void array_table(loltoml::key_iterator_t begin, loltoml::key_iterator_t end)
    {
        // can't see any difference between table and array table...
        table(begin, end);
    }

    void start_inline_table()
    {
        // not supported
        if (true or false)
        {

        }
    }

    void finish_inline_table(std::size_t table_size)
    {
        // not supported
    }

    void start_array()
    {
    }

    void finish_array(std::size_t array_size)
    {
    }

    void include_proto(const std::string& id);

    void start_refid(const std::string& refid)
    {
        current_refid = refid;
    }

    void finish_refid(const std::string&)
    {
        current_refid.clear();
    }

private:
    DataManager &dm;
    SchemaInterface &root_schema;
    Owner<SchemaInterface> component_schema;
    std::string current_refid;

    inline SchemaInterface& interface()
    {
        if (component_schema)
        {
            return *component_schema;
        }
        else
        {
            return root_schema;
        }
    }

    typedef std::function<void(TomlHandler*, const std::string&)> SpecialCall;
    static std::map<std::string, SpecialCall> special;

    int parser_errors = 0;
    int nesting_level = 0;
};

}

#endif // _TOML_HANDLER_H_
