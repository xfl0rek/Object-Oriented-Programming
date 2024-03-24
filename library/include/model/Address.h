#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
private:
    std::string city = "";
    std::string street = "";
    std::string number = "";

public:
    Address(const std::string &city, const std::string &street, const std::string &number);
    ~Address();

    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getNumber() const;

    void setCity(std::string city);
    void setStreet(std::string street);
    void setNumber(std::string number);

    std::string getInfo() const;
};

#endif
