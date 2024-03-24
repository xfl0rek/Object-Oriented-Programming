#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <string>
#include "typedefs.h"
#include <functional>

template<class T> class Repository
{
protected:
    std::vector<T> elements;

public:
    Repository();
    virtual ~Repository();

    T get(unsigned int id) const;
    void add(T element);
    T find(const std::function<bool(T)> &predicate) const;
    std::vector<T> findAll(const std::function<bool(T)> &predicate) const;
    std::string report() const;
    int size() const;
    void remove(T element);
};

#endif
