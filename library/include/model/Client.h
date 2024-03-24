#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "model/Address.h"
#include "typedefs.h"
#include "model/ClientType.h"

class Client
{
private:
    std::string firstName = "";
    std::string lastName = "";
    const std::string personalID = "";
    bool isArchive;

    AddressPtr address;
    ClientTypePtr clientType;

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr address);
    ~Client();

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalID() const;
    bool isArchived() const;
    AddressPtr getAddress() const;
    ClientTypePtr getClientType() const;

    void setFirstName(const std::string &newFirstName);
    void setLastName(const std::string &newLastName);
    void setClientType(const ClientTypePtr &newClientType);
    void setAddress(const AddressPtr &newAddress);
    void setArchive(bool status);

    std::string getInfo() const;
    double calculateClientDiscount(double price) const;
};

#endif
