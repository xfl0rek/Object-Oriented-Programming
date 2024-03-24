#include <boost/test/unit_test.hpp>
#include "managers/MealManager.h"
#include "repositories/Repository.h"
#include "model/Meal.h"

BOOST_AUTO_TEST_SUITE(TestSuiteMealManager)

BOOST_AUTO_TEST_CASE(orderMealTest)
{
    MealRepositoryPtr testMealRepository;
    testMealRepository = std::make_shared<Repository<MealPtr>>();
    std::string mealName = "Pizza";
    int price = 30;
    int grammage = 150;
    MealPtr meal(new Meal(mealName, price, grammage));
    testMealRepository->add(meal);
    MealManager mealManager(testMealRepository);
    BOOST_TEST(mealManager.orderMeal(mealName) == meal);
}

BOOST_AUTO_TEST_SUITE_END()