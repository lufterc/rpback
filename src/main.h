#ifndef MAIN_H_
#define MAIN_H_

#include <cstdint>
#include <functional>
#include <memory>
#include <map>

namespace rpback
{

// Localization string ID
typedef uint64_t StringID;

// World time
typedef uint64_t Time;
typedef uint64_t Duration;

// Location coordinate
typedef int64_t Coord;

// Basic string
typedef std::string String;

// Entity index
typedef size_t Id;

} // namespace rpback

#endif // MAIN_H_
