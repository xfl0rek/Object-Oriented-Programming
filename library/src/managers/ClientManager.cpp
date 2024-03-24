//
// Created by student on 09.06.23.
//

#include "managers/ClientManager.h"
#include "repositories/Repository.h"
#include "model/Client.h"
#include "exceptions/ParameterException.h"

ClientManager::ClientManager(const ClientRepositoryPtr &clientRepository) : clientRepository(clientRepository) {

    if(clientRepository == nullptr) { throw ParameterException("Nie mozna utworzyc. Potrzebne jest repozytorium!"); }
}

ClientManager::~ClientManager() {}

// Tworzy objekt client i zwraca na niego wskaźnik
ClientPtr ClientManager::registerClient(const std::string &firstName, const std::string &lastName,
                                        const std::string &personalID, const AddressPtr &address) {
    ClientPtr clientCheck = getClient(personalID);
    if (clientCheck == nullptr) {
        ClientPtr newClient = std::make_shared<Client>(firstName, lastName, personalID, address);
        clientRepository->add(newClient);
        return newClient;
    } else {
        clientCheck->setArchive(false);      // gdy klient był zarchiwizowany dokonuje się dearchiwizacja
        clientCheck->setFirstName(firstName);            // ustawione zostają nowe dane klienta
        clientCheck->setLastName(lastName);
        clientCheck->setAddress(address);

        return clientCheck;
    }
}

// ustawia pole isArchive objektu na true
void ClientManager::unregisterClient(const ClientPtr &client) {
    client->setArchive(true);
}

// metoda zwraca nullptr jeśli klient nie istnieje
const ClientPtr ClientManager::getClient(const std::string &personalID) const {
    ClientPredicate predicate = [personalID](const ClientPtr ptr) {
        return ptr->getPersonalID() == personalID;
    };
    return clientRepository->find(predicate);
}

std::string ClientManager::getAllClientsReport() const {
    return clientRepository->report();
}

