#include "model/Default.h"

double Default::applyDiscount(double price) const
{
    return price;
}

std::string Default::getInfo() const
{
    return "default";
}