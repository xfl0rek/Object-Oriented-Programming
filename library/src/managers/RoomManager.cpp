//
// Created by student on 09.06.23.
//
#include "managers/RoomManager.h"
#include "repositories/Repository.h"
#include "model/Room.h"
#include "exceptions/ParameterException.h"

RoomManager::RoomManager(const RoomRepositoryPtr &roomRepository) : roomRepository(roomRepository) {
    if(roomRepository == nullptr) { throw ParameterException("Nie mozna utworzyc. Potrzebne jest repozytorium!"); }
}

RoomManager::~RoomManager() {}

// Tworzy objekt room i zwraca na niego wskaźnik. Jeśli room jest już stworzony zamienia jego pole isArchive na false
// (jeśli wcześniej było na true) i zwraca wskaźnik ten obiekt
const RoomPtr RoomManager::registerRoom(int basePrice, int roomNumber, int roomCapacity) {
    RoomPtr roomCheck = getRoom(roomNumber);
    if (roomCheck == nullptr) {
        RoomPtr newRoom = std::make_shared<Room>(basePrice, roomNumber, roomCapacity);
        roomRepository->add(newRoom);
        return newRoom;
    } else {
        if (roomCheck->isArchived()) {                // gdy pokój był zarchiwizowany dokonuje się dearchiwizacja
            roomCheck->setArchive(false);
        }
        return roomCheck;
    }
}

// ustawia pole isArchive objektu na true
void RoomManager::unregisterRoom(RoomPtr room) {
    room->setArchive(true);
}

// jeśli pokój nie zostanie znaleziony, zwrócony zostanie nullptr
const RoomPtr RoomManager::getRoom(int roomNumber) const {
    RoomPredicate predicate = [roomNumber](const RoomPtr ptr) {
        return ptr->getRoomNumber() == roomNumber;
    };
    return roomRepository->find(predicate);
}

// zwraca pierwszy dopasoany do parametrów wskaźnik na objekt pokoju
const RoomPtr RoomManager::getRoom(int price, int roomCapacity) const {
    RoomPredicate predicate = [price, roomCapacity](const RoomPtr ptr) {
        return (ptr->getBasePrice() <= price && ptr->getRoomCapacity() == roomCapacity);
    };
    return roomRepository->find(predicate);
}

std::string RoomManager::getAllRooms() const {
    return roomRepository->report();
}

