#include "model/Address.h"
#include <sstream>
#include "exceptions/ParameterException.h"

Address::Address(const std::string &city, const std::string &street,
                 const std::string &number) : city(city), street(street), number(number) {

    if(city.empty()) { throw ParameterException("Blad! Niepoprawne miasto. Miasto nie zostalo zmienione."); }
    if(street.empty()) { throw ParameterException("Blad! Niepoprawna ulica. Ulica nie zostala zmieniona."); }
    if(number.empty()) { throw ParameterException("Blad! Niepoprawny numer ulicy. Numer ulicy nie zostal zmieniony."); }
}

Address::~Address() {}

const std::string &Address::getCity() const
{
    return city;
}

const std::string &Address::getStreet() const
{
    return street;
}

const std::string &Address::getNumber() const
{
    return number;
}

void Address::setCity(std::string city)
{
    if(!city.empty())
    {
        this->city = city;
    }
}

void Address::setStreet(std::string street)
{
    if(!street.empty())
    {
        this->street = street;
    }
}

void Address::setNumber(std::string number)
{
    if(!number.empty())
    {
        this->number = number;
    }
}

std::string Address::getInfo() const
{
    std::stringstream addressData;
    addressData << "miasto: " << city << ", ulica i numer ulicy: " << street << " " << number << std::endl;
    return addressData.str();
}