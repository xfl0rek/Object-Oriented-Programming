//
// Created by student on 09.06.23.
//

#ifndef REPOZYTORIUM_RENTMANAGER_H
#define REPOZYTORIUM_RENTMANAGER_H
#include "typedefs.h"
#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>

class RentManager {
private:
    RentRepositoryPtr currentRents;
    RentRepositoryPtr archiveRents;

private:
    // zmiana typu klienta na podawie ile wydał pieniędzy za najem pokoji. (Zliczane są tylko zakończone wypożyczenia)
    void changeClientType(const ClientPtr &client) const;

public:
    RentManager(const RentRepositoryPtr &currentRents, const RentRepositoryPtr &archiveRents);

    virtual ~RentManager();

    // Tworzy objekt rent i zwraca na niego wskaźnik. Jeśli pokój jest już przypisany do wypożecznia zwraca nullptr
    RentPtr
    rentRoom(const ClientPtr &client, const RoomPtr &room, const boost::posix_time::ptime &beginTime = boost::posix_time::second_clock::local_time());

    // Przenosi objekt room z repozytorium currentRents do archiveRents
    void returnRoom(const RoomPtr& room) const;

    // Jeśli wypożyczenie nie zostanie znalezione zwraca nullptr
    RentPtr getRent(const RoomPtr &room) const;

    // zwraca informacje o wszystkich objektach w repozytorium obecnych wypożyczeń
    std::string getAllCurrentRents() const;

    // zwraca informacje o wszystkich objektach w repozytorium archiwalnych wypożyczeń
    std::string getAllArchiveRents() const;
};



#endif //REPOZYTORIUM_RENTMANAGER_H
