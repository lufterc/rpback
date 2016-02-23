#ifndef _SCHEMA_TYPES_H_
#define _SCHEMA_TYPES_H_

#include "main.h"

namespace rpback
{

template <typename Struct>
class SchemaVisitorBase;

template <typename Struct>
class SchemaVisitorInteger;

template <typename Struct>
class SchemaVisitorString;

template <typename Struct>
class SchemaBase
{
public:
    virtual bool accept(int integer, Struct&) const
    {
        return false;
    }

    virtual bool accept(std::string &string, Struct&) const
    {
        return false;
    }
};

template <typename Struct>
class SchemaDuration : public SchemaBase<Struct>
{
public:
    SchemaDuration(Duration Struct::*_ptr)
        : ptr(_ptr) {}

    virtual bool accept(int integer, Struct &data) const
    {
        data.*ptr = integer;
    }

private:
    Duration Struct::*ptr;
};

template <typename Struct>
class SchemaString : public SchemaBase<Struct>
{
public:
    SchemaString(String Struct::*_ptr)
        : ptr(_ptr) {}

    virtual bool accept(std::string &string, Struct &data) const
    {
        data.*ptr = string;
    }

private:
    String Struct::*ptr;
};

template <typename Struct>
class SchemaMap
{
public:
    template <template <typename S> class Scheme, typename Type>
    void add(const char *id, Type Struct::*ptr)
    {
        schema[id] = new Scheme<Struct>(ptr);
    }

    SchemaBase<Struct>* find(const char *id)
    {
        auto field = schema.find(id);
        if (field == schema.end())
        {
            return nullptr;
        }

        return field->second;
    }

private:
    std::map<std::string, SchemaBase<Struct>*> schema;
};

} // namespace rpback

#endif // _SCHEMA_TYPES_H_
