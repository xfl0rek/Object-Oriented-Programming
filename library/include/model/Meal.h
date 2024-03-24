//
// Created by student on 08.06.23.
//

#ifndef REPOZYTORIUM_MEAL_H
#define REPOZYTORIUM_MEAL_H
#include <string>

class Meal
{
private:
    std::string mealName = "";
    int price = 0;
    int grammage = 0;
public:
    Meal(std::string mealName, int price, int grammage);
    ~Meal();
    std::string getMealName() const;
    int getPrice() const;
    int getGrammage() const;
    void setPrice(int newPrice);
    std::string getInfo() const;

};
#endif //REPOZYTORIUM_MEAL_H
