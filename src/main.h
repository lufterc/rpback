#ifndef MAIN_H_
#define MAIN_H_

#include <cstdint>
#include <functional>
#include <memory>
#include <map>

namespace rpback
{

// World time
typedef std::uint64_t Duration;

// Location coordinate
typedef std::int64_t Coord;

// Physical characteristics
typedef std::int64_t Property;

// Object shape
typedef std::uint64_t Shape;

// Ownership semantics
template <typename T>
using Owner = std::unique_ptr<T>;

// Basic string
typedef std::string String;

// Entity index
typedef std::uint64_t Id;

// Entity index
template <typename T>
using IndexMap = std::map<Id, T*>;

// Flag
typedef bool Flag;

} // namespace rpback

#endif // MAIN_H_
