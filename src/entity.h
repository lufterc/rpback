#ifndef ENTITY_H
#define ENTITY_H

#include "index.h"
#include "schema_types.h"
#include "main.h"

namespace rpback
{

class Location;

class Entity;
class EntityComponent;

class EntityCharacterComponent;
class EntityPersonalityComponent;
class EntityPlayerCharacterComponent;
class EntityDoorComponent;
class EntityContainerComponent;
class EntityMeleeWeaponComponent;
class EntityRangedWeaponComponent;
class EntityClothingComponent;
class EntityLockpickComponent;
class EntityQuestItemComponent;
class EntityDoorKeyComponent;

class EntityComponent
{
public:
    template <typename T>
    T* get()
    {
        T* ptr = nullptr;
        this->get(&ptr);
        return ptr;
    }

    virtual void get(EntityCharacterComponent**) {}
    virtual void get(EntityPersonalityComponent**) {}
    virtual void get(EntityPlayerCharacterComponent**) {}
    virtual void get(EntityDoorComponent**) {}
    virtual void get(EntityContainerComponent **) {}
};

class Entity
{
public:
    template <typename T>
    T* has()
    {
        T* ptr = nullptr;
        for (auto i : components)
        {
            i->get(&ptr);
            if (ptr != nullptr)
            {
                return ptr;
            }
        }
    }

private:
    Coord pos_x;
    Coord pos_y;
    Property item_weight;
    String prototype_id; // if prototype_id is empty - this is a custom object,
    // and 100% created from savegame - so during serialization, all fields are
    // saved, not only the dynamic ones, but persistent ones too

private:
    Id uuid = 0;
    OwnerContainer<EntityComponent> components;

private:
    friend class SchemaInstance<Entity>;
    static struct Schema : public SchemaMap<Entity>
    {
        Schema()
        {
            dynamic<SchemaString>("_proto", &Entity::prototype_id);
            component<EntityCharacterComponent>("character", nullptr);
            component<EntityPersonalityComponent>("personality", nullptr);
        }
    }
    schema;
};

#if 0
class Body
{
public:
    Body(Location *location, Coord x, Coord y);
    Body() {}

    void teleportTo(Coord x, Coord y);
    void moveTo(Coord x, Coord y);

public:
    Coord positionX() const { return position_x; }
private:
    Coord position_x;

public:
    Coord positionY() const { return position_y; }
private:
    Coord position_y;

private:
    Shape shape; // form: "3x5" 64 bits: up to 8x8?

private:
    Id chunk_id;
    Location *location;
    Flag traveller = false; // ? - here, in Body, not in Entity?

    // component list
    // getComponent()

    //std::weak_ptr<Controller> controller;

    // entity components
    Owner<Entity> entity = Owner<Entity>(new Entity()); // entity is given away when player picks item up
};
#endif



class ComponentFunction
{
public:
    virtual bool check(EntityCharacterComponent *) { return true; }
    virtual void accept(EntityCharacterComponent *) {}
};

class EntityMeleeWeaponComponent : public EntityComponent
{
    // static list of component functions
};

class EntityCharacterComponent : public EntityComponent
{
public:
    virtual void accept(ComponentFunction *item)
    {
        item->accept(this);
    }

    virtual bool check(ComponentFunction *item)
    {
        return item->check(this);
    }
};

} // namespace rpback

#endif // ENTITY_H
