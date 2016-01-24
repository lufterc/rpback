#ifndef INDEX_H
#define INDEX_H

#include <vector>
#include <typeinfo>
#include "main.h"

namespace rpback
{

template <class T>
class Index
{
public:
    size_t push_someplace(T &v);
    size_t push_someplace(T &&v);
    void pop_from(Id id);

    T& operator[](Id);
    const T& operator[](Id) const;

    size_t count() const;
    size_t free() const;
    size_t reserved() const;

private:
    template <class V>
    size_t emplace(V);

    template <class V>
    void reset(Id id, decltype(&V::reset))
    {
        data[id].reset();
    }

    template <class V>
    void reset(Id id, ...)
    {
    }

    std::vector<T> data;
    std::vector<size_t> free_stuff;
};

template <class T>
template <class V>
size_t Index<T>::emplace(V value)
{
    if (free())
    {
        size_t result = free_stuff.back();
        data[result] = value;
        free_stuff.pop_back();
        return result;
    }

    data.push_back(value);
    return data.size() - 1;
}

template <class T>
size_t Index<T>::push_someplace(T &v)
{
    return emplace(v);
}

template <class T>
size_t Index<T>::push_someplace(T &&v)
{
    return emplace(std::move(v));
}

template <class T>
void Index<T>::pop_from(Id id)
{
    reset<T>(id, 0);
    free_stuff.push_back(id);
}

template <class T>
T& Index<T>::operator[](Id id)
{
    return data[id];
}

template <class T>
const T& Index<T>::operator[](Id id) const
{
    return data[id];
}

template <class T>
size_t Index<T>::count() const
{
    return data.size() - free_stuff.size();
}

template <class T>
size_t Index<T>::free() const
{
    return free_stuff.size();
}

template <class T>
size_t Index<T>::reserved() const
{
    return data.size();
}

} // namespace rpback

#endif // INDEX_H
