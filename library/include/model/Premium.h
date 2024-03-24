#ifndef PREMIUM_H
#define PREMIUM_H

#include "model/ClientType.h"

class Premium : public ClientType
{
public:
    Premium() = default;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

#endif
