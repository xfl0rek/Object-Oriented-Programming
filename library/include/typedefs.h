#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <memory>
#include <functional>

class Client;
class Address;
class ClientType;
class Room;
class Rent;
class Meal;
class ClientManager;
class MealManager;
class RentManager;
class RoomManager;

template<class T>
class Repository;

template <class M>
        using Ptr = std::shared_ptr<M>;
typedef Ptr<Client> ClientPtr;
typedef Ptr<Address> AddressPtr;
typedef Ptr<ClientType> ClientTypePtr;
typedef Ptr<Room> RoomPtr;
typedef Ptr<Rent> RentPtr;
typedef Ptr<Meal> MealPtr;
typedef Ptr<ClientManager> ClientManagerPtr;
typedef Ptr<MealManager> MealManagerPtr;
typedef Ptr<RentManager> RentManagerPtr;
typedef Ptr<RoomManager> RoomManagerPtr;

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RoomPtr)> RoomPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;
typedef std::function<bool(MealPtr)> MealPredicate;

typedef std::shared_ptr<Repository<ClientPtr>> ClientRepositoryPtr;
typedef std::shared_ptr<Repository<RoomPtr>> RoomRepositoryPtr;
typedef std::shared_ptr<Repository<RentPtr>> RentRepositoryPtr;
typedef std::shared_ptr<Repository<MealPtr>> MealRepositoryPtr;

#endif
