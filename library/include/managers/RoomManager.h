//
// Created by student on 09.06.23.
//

#ifndef REPOZYTORIUM_ROOMMANAGER_H
#define REPOZYTORIUM_ROOMMANAGER_H
#include "typedefs.h"

class RoomManager {
private:
    RoomRepositoryPtr roomRepository;

public:
    RoomManager(const RoomRepositoryPtr &roomRepository);

    virtual ~RoomManager();

    // Tworzy objekt room i zwraca na niego wskaźnik. Jeśli room jest już stworzony zamienia jego pole isArchive na false
    // (jeśli wcześniej było na true) i zwraca wskaźnik ten obiekt
    const RoomPtr registerRoom(int basePrice, int roomNumber, int roomCapacity);

    // ustawia pole isArchive objektu na true
    void unregisterRoom(const RoomPtr room);

    // jeśli pokój nie zostanie znaleziony, zwrócony zostanie nullptr
    const RoomPtr getRoom(int roomNumber) const;

    // zwraca pierwszy dopasoany do parametrów wskaźnik na objekt pokoju
    const RoomPtr getRoom(int price, int roomCapacity) const;

    // zwraca informacje o wszystkich objektach w repozytorium
    std::string getAllRooms() const;
};
#endif //REPOZYTORIUM_ROOMMANAGER_H
