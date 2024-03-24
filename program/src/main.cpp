#include <iostream>
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/Address.h"
#include "typedefs.h"
#include "model/Default.h"
#include "model/Premium.h"
#include "model/Rent.h"
#include "model/Room.h"
#include "model/Meal.h"
#include "repositories/Repository.h"
#include "managers/ClientManager.h"
#include "managers/MealManager.h"
#include "managers/RentManager.h"
#include "managers/RoomManager.h"
#include "menu/Menu.h"

int main()
{
    ClientRepositoryPtr clientRepository = std::make_shared<Repository<ClientPtr>>();
    MealRepositoryPtr mealRepository = std::make_shared<Repository<MealPtr>>();
    RentRepositoryPtr currentRents = std::make_shared<Repository<RentPtr>>();
    RentRepositoryPtr archiveRents = std::make_shared<Repository<RentPtr>>();
    RoomRepositoryPtr roomRepository = std::make_shared<Repository<RoomPtr>>();

    ClientManagerPtr clientManager(new ClientManager(clientRepository));
    MealManagerPtr mealManager(new MealManager(mealRepository));
    RentManagerPtr rentManager(new RentManager(currentRents, archiveRents));
    RoomManagerPtr roomManager(new RoomManager(roomRepository));

    MealPtr meal1(new Meal("pizza z serem", 25, 150));
    MealPtr meal2(new Meal("pizza z szynka", 30, 150));
    MealPtr meal3(new Meal("pizza z warzywami", 28, 150));
    MealPtr meal4(new Meal("zupa pomidorowa", 15, 120));
    MealPtr meal5(new Meal("rosol", 12, 120));
    MealPtr meal6(new Meal("kotlet schabowy", 25, 160));
    MealPtr meal7(new Meal("kotlet mielony", 23, 140));
    MealPtr meal8(new Meal("stek", 50, 180));

    mealRepository->add(meal1);
    mealRepository->add(meal2);
    mealRepository->add(meal3);
    mealRepository->add(meal4);
    mealRepository->add(meal5);
    mealRepository->add(meal6);
    mealRepository->add(meal7);
    mealRepository->add(meal8);

    Menu menu(clientManager, mealManager, rentManager, roomManager);

    menu.start();

	return 0;
}
