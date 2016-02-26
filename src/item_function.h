#ifndef ITEM_FUNCTION_H
#define ITEM_FUNCTION_H

#include <string>
#include "main.h"

namespace rpback {

#if 0
class Creature;
class Door;

class WeaponFunction;
class LockpickFunction;

class ItemFunction
{
public:
    StringID name() const { return fun_name; }

    virtual bool check(Creature *) { return false; }
    virtual void visit(Creature *) {}

    virtual bool check(Door *) { return false; }
    virtual void visit(Door *) {}

    virtual WeaponFunction *isWeapon() { return nullptr; }
    virtual LockpickFunction *isLockpick() { return nullptr; }

private:
    StringID fun_name = 0;
    // LocaleString fun_name;
};

// class Open
// class Close
// class Crack
// class Jam

class WeaponFunction
{
public:
    virtual WeaponFunction *isWeapon() { return this; }
};
#endif

#if 0
class MeleeWeaponComponent;
class ProjectileWeaponComponent;
class LockpickToolComponent;
class KeyToolComponent;

class ItemComponent
{
public:
    /**
     * @brief Get component name for serialization
     * @return String name of component for saving in kv-storage
     */
    virtual const char *name() const { return "abstract"; }

    virtual MeleeWeaponComponent *meleeWeapon() { return nullptr; }
    virtual ProjectileWeaponComponent *projectileWeapon() { return nullptr; }
    virtual LockpickToolComponent *lockpickToolComponent() { return nullptr; }
    virtual KeyToolComponent *keyToolComponent() { return nullptr; }

private:

};

class MeleeWeaponComponent : public ItemComponent
{
public:
    virtual const char *name() const { return "melee_weapon"; }
};

class ProjectileWeaponComponent : public ItemComponent
{
public:
    virtual const char *name() const { return "projectile_weapon"; }
};

class LockpickComponent : public ItemComponent
{
public:
    virtual const char *name() const { return "lockpick_tool"; }
};
#endif

} // namespace rpback

#endif // ITEM_FUNCTION_H
