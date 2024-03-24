#include "model/Room.h"
#include <sstream>
#include "exceptions/ParameterException.h"

Room::Room(int basePrice, int roomNumber, int roomCapacity) : basePrice(basePrice), roomNumber(roomNumber), roomCapacity(roomCapacity) {

    if (basePrice <= 0) { throw ParameterException("Niewlasciwa cena pokoju!"); }
    if (roomNumber <= 0) { throw ParameterException("Niewlasciwy numer pokoju!"); }
    if (roomCapacity <= 0) { throw ParameterException("Niewlasciwa pojemnosc pokoju!"); }
}

Room::~Room() {}

unsigned int Room::getBasePrice() const
{
    return basePrice;
}

unsigned int Room::getRoomNumber() const
{
    return roomNumber;
}

unsigned int Room::getRoomCapacity() const
{
    return roomCapacity;
}

bool Room::isArchived() const
{
    return isArchive;
}

void Room::setBasePrice(int newBasePrice)
{
    if(newBasePrice >= 0)
    {
        basePrice = newBasePrice;
    }
}

void Room::setArchive(bool status)
{
    isArchive = true;
}

std::string Room::getInfo() const
{
    std::stringstream roomData;
    roomData << "Cena za pokoj: " << basePrice << std::endl
    << "Numer pokoju: " << roomNumber << std::endl
    << "Pojemnosc pokoju: " << roomCapacity << std::endl;
    return roomData.str();
}