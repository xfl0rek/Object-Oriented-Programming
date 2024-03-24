#ifndef DEFAULT_H
#define DEFAULT_H

#include "model/ClientType.h"

class Default : public ClientType
{
public:
    Default() = default;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

#endif
