#ifndef MENU_H
#define MENU_H

#include "typedefs.h"
#include <string>

class Menu
{
private:
    ClientManagerPtr clientManager;
    MealManagerPtr mealManager;
    RentManagerPtr rentManager;
    RoomManagerPtr roomManager;

public:
    Menu(const ClientManagerPtr &clientManager, const MealManagerPtr &mealManager, const RentManagerPtr &rentManager,
         const RoomManagerPtr &roomManager);
    virtual ~Menu();

    void start();
    void client();
    void meal();
    void rent();
    void room();

    void saveAppState(const std::string &fileName);
};

#endif
