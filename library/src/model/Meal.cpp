//
// Created by student on 08.06.23.
//

#include "model/Meal.h"
#include <sstream>
#include "exceptions/ParameterException.h"

Meal::Meal(std::string mealName, int price, int grammage): mealName(mealName), price(price), grammage(grammage) {

    if(price <= 0) { throw ParameterException("Blad! Podano niepoprawna wartosc ceny."); }
}

Meal::~Meal(){}

std::string Meal::getMealName() const
{
    return mealName;
}

int Meal::getPrice() const
{
    return price;
}

int Meal::getGrammage() const
{
    return grammage;
}

void Meal::setPrice(int newPrice)
{
    if(newPrice > 0)
    {
        price = newPrice;
    }
}

std::string Meal::getInfo() const
{
    std::stringstream mealData;
    mealData << "Rodzaj posilku: " << mealName << std::endl;
    mealData << "Cena: " << price << " zlotych" << std::endl;
    mealData << "Gramatura: " << grammage << " g" << std::endl;
    return mealData.str();
}




