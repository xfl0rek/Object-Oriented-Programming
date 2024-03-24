#ifndef CLIENTTYPE_H
#define CLIENTTYPE_H

#include <string>

class ClientType
{
public:
    ~ClientType() = default;
    virtual double applyDiscount(double price) const = 0;
    virtual std::string getInfo() const = 0;
};

#endif
