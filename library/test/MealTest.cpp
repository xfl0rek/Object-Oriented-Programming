#include <boost/test/unit_test.hpp>
#include "model/Meal.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteMeal)

BOOST_AUTO_TEST_CASE(ConstructorTest)
{
    std::string mealName = "Pizza";
    int price = 30;
    int grammage = 150;
    MealPtr testMeal(new Meal(mealName, price, grammage));
    BOOST_TEST(testMeal->getMealName() == mealName);
    BOOST_TEST(testMeal->getPrice() == price);
    BOOST_TEST(testMeal->getGrammage() == grammage);
}

BOOST_AUTO_TEST_CASE(setPriceTest)
{
    MealPtr testMeal(new Meal("Pizza", 30, 150));
    testMeal->setPrice(50);
    BOOST_TEST(testMeal->getPrice() == 50);
    testMeal->setPrice(-60);
    BOOST_TEST(testMeal->getPrice() == 50);
}

BOOST_AUTO_TEST_CASE(getInfoTest)
{
    MealPtr testMeal(new Meal("Pizza", 30, 150));
    BOOST_TEST(testMeal->getInfo() == "Rodzaj posilku: Pizza\nCena: 30 zlotych\nGramatura: 150 g\n");
}

BOOST_AUTO_TEST_SUITE_END()