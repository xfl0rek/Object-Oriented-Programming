#include "model/Client.h"
#include "model/ClientType.h"
#include "model/Default.h"
#include <sstream>
#include "exceptions/ParameterException.h"

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID,
               AddressPtr address) : firstName(firstName), lastName(lastName), personalID(personalID), address(address) {

    isArchive = false;
    clientType = std::make_shared<Default>();

    if(address == nullptr) { throw ParameterException("Blad! Niepoprawny adres zamieszkania klienta. Adres nie zostal zmieniony."); }
    if(firstName.empty()) { throw ParameterException("Blad! Niepoprawne imie. Imie nie zostalo zmienione."); }
    if(lastName.empty()) { throw ParameterException("Blad! Niepoprawne nazwisko. Nazwisko nie zostalo zmienione."); }
    if(clientType == nullptr) { throw ParameterException("Blad! Niepoprawny typ klienta. Typ klienta nie zostal zmieniony."); }
}

Client::~Client() {}

const std::string &Client::getFirstName() const
{
    return firstName;
}

const std::string &Client::getLastName() const
{
    return lastName;
}

const std::string &Client::getPersonalID() const
{
    return personalID;
}

AddressPtr Client::getAddress() const
{
    return address;
}

ClientTypePtr Client::getClientType() const
{
    return clientType;
}

bool Client::isArchived() const
{
    return isArchive;
}

void Client::setFirstName(const std::string &newFirstName)
{
    if(!newFirstName.empty())
    {
        this->firstName = newFirstName;
    }
}

void Client::setLastName(const std::string &newLastName)
{
    if(!newLastName.empty())
    {
        this->lastName = newLastName;
    }
}

void Client::setAddress(const AddressPtr &newAddress)
{
    if(newAddress != nullptr)
    {
        this->address = newAddress;
    }

}

void Client::setClientType(const ClientTypePtr &newClientType)
{
    if(newClientType != nullptr)
    {
        this->clientType = newClientType;
    }
}

void Client::setArchive(bool status)
{
    isArchive = true;
}

std::string Client::getInfo() const
{
    std::stringstream clientData;
    clientData << "Imie i nazwisko: " << firstName << " " << lastName << std::endl
    << "Numer pesel klienta: " << personalID << std::endl
    << "Typ klienta: " << getClientType()->getInfo() << std::endl
    << "Czy zarchiwizowany: " << (isArchived() ? "true" : "false") << std::endl
    << "Adres zamieszkania klienta: " << address->getInfo();
    return clientData.str();
}

double Client::calculateClientDiscount(double price) const
{
    return clientType->applyDiscount(price);
}