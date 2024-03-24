#include "model/Premium.h"

double Premium::applyDiscount(double price) const
{
    return 50.0 / 100.0 * price;
}

std::string Premium::getInfo() const
{
    return "premium";
}