//
// Created by student on 09.06.23.
//

#ifndef REPOZYTORIUM_MEALMANAGER_H
#define REPOZYTORIUM_MEALMANAGER_H
#include "typedefs.h"
#include <string>
class MealManager
{
private:
    MealRepositoryPtr mealRepository;
public:
    MealManager(const MealRepositoryPtr &mealRepository);
    virtual ~MealManager();
    MealPtr orderMeal(const std::string &mealName) const;
    std::string getAllMeals() const;
};

#endif //REPOZYTORIUM_MEALMANAGER_H
