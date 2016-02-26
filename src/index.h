#ifndef INDEX_H
#define INDEX_H

#include <vector>
#include <memory>
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
size_t Index<T>::push_someplace(T &v)
{
    if (free())
    {
        size_t result = free_stuff.back();
        data[result] = v;
        free_stuff.pop_back();
        return result;
    }
    data.push_back(v);
    return data.size() - 1;
}

template <class T>
size_t Index<T>::push_someplace(T &&v)
{
    if (free())
    {
        size_t result = free_stuff.back();
        data[result] = std::move(v);
        free_stuff.pop_back();
        return result;
    }
    data.push_back(std::move(v));
    return data.size() - 1;
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

template <typename T>
class Container : public std::vector<T>
{
public:
    typename Container::const_iterator
    erase_fast(typename Container::iterator iterator)
    {
        if (std::next(iterator) != this->end())
        {
            *iterator = std::move(*this->rbegin());
        }

        this->pop_back();
        return iterator;
    }

    void erase_fast(size_t index)
    {
        (*this)[index] = std::move(this->back());
        this->pop_back();
    }
};

template <typename T>
class OwnerContainer : public Container<std::unique_ptr<T>>
{
public:
    void push_back(T* val)
    {
        Container<std::unique_ptr<T>>::push_back(std::unique_ptr<T>(val));
    }
};

} // namespace rpback

#endif // INDEX_H
