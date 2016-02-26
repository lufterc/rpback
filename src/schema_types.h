#ifndef _SCHEMA_TYPES_H_
#define _SCHEMA_TYPES_H_

#include <functional>
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
    virtual bool integer(int integer, Struct&) const
    {
        return false;
    }

    virtual bool string(const std::string &string, Struct&) const
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

    virtual bool integer(int integer, Struct &data) const override
    {
        if (integer < 0)
        {
            return false;
        }

        data.*ptr = integer;
        return true;
    }

private:
    Duration Struct::*ptr;
};

template <typename Struct>
class SchemaCoord : public SchemaBase<Struct>
{
public:
    SchemaCoord(Coord Struct::*field_ptr)
        : ptr(field_ptr) {}

    virtual bool integer(int integer, Struct &data) const override
    {
        data.*ptr = integer;
        return true;
    }

private:
    Coord Struct::*ptr;
};

template <typename Struct>
class SchemaString : public SchemaBase<Struct>
{
public:
    SchemaString(String Struct::*field_ptr)
        : ptr(field_ptr) {}

    virtual bool string(const std::string &string, Struct &data) const override
    {
        data.*ptr = string;
        return true;
    }

private:
    String Struct::*ptr;
};



class SchemaInterface
{
public:
    virtual bool string(const std::string& string) { return false; }
    virtual bool integer(std::int64_t integer) { return false; }
    virtual bool real(double real) { return false; }
    virtual bool key(const std::string &key) { return false; }
    virtual Owner<SchemaInterface> component(const std::string& key,
                                             const std::string& uuid) = 0;
};

template <typename Struct>
class SchemaInstance : public SchemaInterface
{
public:
    SchemaInstance(Struct &reference_instance)
        : instance(reference_instance)
    {}

    virtual bool key(const std::string &key) override
    {
        current = Struct::schema.find(key);
        return (current != nullptr);
    }

    virtual bool integer(std::int64_t integer) override
    {
        if (!current)
        {
            return false;
        }
        return current->integer(integer, instance);
    }

    virtual bool string(const std::string& string) override
    {
        if (!current)
        {
            return false;
        }
        return current->string(string, instance);
    }

    virtual Owner<SchemaInterface> component(const std::string& key,
                                       const std::string& uuid) override
    {
        auto call = Struct::schema.component(key);
        if (call == nullptr)
        {
            return nullptr;
        }
        return call(&instance, uuid);
    }

private:
    Struct &instance;
    SchemaBase<Struct>* current = nullptr;
};


template <typename Struct>
class SchemaMap
{
public:
    SchemaBase<Struct>* find(const std::string &id)
    {
        auto field = schema.find(id);
        if (field == schema.end())
        {
            return nullptr;
        }

        return field->second.get();
    }

    typedef std::function
    <Owner<SchemaInterface>(Struct *, const std::string&)> ComponentCall;

    ComponentCall component(const std::string &id)
    {
        auto field = components.find(id);
        if (field == components.end())
        {
            return nullptr;
        }

        return field->second;
    }

protected:
    template <template <typename S> class Schema, typename Type>
    void persistent(const std::string& id, Type Struct::* ptr)
    {
        schema[id] = std::unique_ptr<Schema<Struct>>(new Schema<Struct>(ptr));
    }

    template <template <typename S> class Schema, typename Type>
    void dynamic(const std::string& id, Type Struct::* ptr)
    {
        persistent<Schema>(id, ptr);
    }

    template <typename CompType, typename CallType>
    void component(const std::string& id, CallType call)
    {
        components[id] = call;
    }

private:
    std::map<std::string, std::unique_ptr<SchemaBase<Struct>>> schema;
    std::map<std::string, ComponentCall> components;
};

} // namespace rpback

#endif // _SCHEMA_TYPES_H_
