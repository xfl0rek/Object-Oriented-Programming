#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room
{
private:
    unsigned int basePrice = 0;
    const unsigned int roomNumber = 0;
    const unsigned int roomCapacity = 0;
    bool isArchive;

public:
    Room(int basePrice, int roomNumber, int roomCapacity);
    ~Room();

    unsigned int getBasePrice() const;
    unsigned int getRoomNumber() const;
    unsigned int getRoomCapacity() const;
    bool isArchived() const;

    void setBasePrice(int newBasePrice);
    void setArchive(bool status);

    std::string getInfo() const;
};

#endif
