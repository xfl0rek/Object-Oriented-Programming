#include "repositories/Repository.h"
#include "model/Client.h"
#include "model/Rent.h"
#include "model/Room.h"
#include "model/Meal.h"

template<class T>
Repository<T>::Repository() = default;

template<class T>
Repository<T>::~Repository() {}

template<class T>
T Repository<T>::get(unsigned int id) const
{
    if(id < size())
    {
        return elements[id];
    }
    else
    {
        return T{};
    }
}

template<class T>
void Repository<T>::add(T element)
{
    if(element != nullptr)
    {
        elements.push_back(element);
    }
}

template<class T>
T Repository<T>::find(const std::function<bool(T)> &predicate) const
{
    for(int i = 0; i < size(); i++)
    {
        T element = get(i);
        if(predicate(element))
        {
            return element;
        }
    }
    return nullptr;
}

template<class T>
std::vector <T> Repository<T>::findAll(const std::function<bool(T)> &predicate) const
{
    std::vector<T> results;
    for(int i = 0; i < size(); ++i)
    {
        T element = get(i);
        if(predicate(element))
        {
            results.push_back(element);
        }
    }
    return results;
}

template<class T>
std::string Repository<T>::report() const
{
    std::string report;
    for(int i = 0; i < size(); i++)
    {
        report += (get(i)->getInfo() + " \n");
    }
    return report;
}

template<class T>
int Repository<T>::size() const
{
    return elements.size();
}

template<class T>
void Repository<T>::remove(T element)
{
    for(int i = 0; i < size(); ++i)
    {
        if(element == get(i))
        {
            elements.erase(elements.begin() + i);
        }
    }
}

template
        class Repository<ClientPtr>;

template
        class Repository<RentPtr>;

template
        class Repository<RoomPtr>;

template
        class Repository<MealPtr>;