//
// Created by student on 09.06.23.
//
#include "managers/MealManager.h"
#include "repositories/Repository.h"
#include "model/Meal.h"
#include "exceptions/ParameterException.h"

MealManager::MealManager(const MealRepositoryPtr &mealRepository) : mealRepository(mealRepository) {

    if(mealRepository == nullptr) { throw ParameterException("Nie mozna utworzyc. Potrzebne jest repozytorium!"); }
}

MealManager::~MealManager() {}

MealPtr MealManager::orderMeal(const std::string &mealName) const
{
    MealPredicate predicate = [mealName](const MealPtr ptr) {
        return ptr->getMealName() == mealName;
    };
    return mealRepository->find(predicate);
}


std::string MealManager::getAllMeals() const {
    return mealRepository->report();
}