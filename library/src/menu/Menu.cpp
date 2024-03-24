#include "menu/Menu.h"
#include "managers/ClientManager.h"
#include "managers/MealManager.h"
#include "managers/RentManager.h"
#include "managers/RoomManager.h"
#include "exceptions/ParameterException.h"
#include "exceptions/LogicException.h"
#include <iostream>
#include "model/Client.h"
#include "model/Meal.h"
#include "model/Room.h"
#include "model/Rent.h"
#include <stdlib.h>
#include <stdio.h>

Menu::Menu(const ClientManagerPtr &clientManager, const MealManagerPtr &mealManager, const RentManagerPtr &rentManager,
           const RoomManagerPtr &roomManager) : clientManager(clientManager), mealManager(mealManager),
           rentManager(rentManager), roomManager(roomManager) {}

Menu::~Menu() {}

void Menu::start()
{

    char choice;
    bool menuExit = false;

    while(!menuExit)
    {
        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "---------------------MENU---------------------" << std::endl;
        std::cout << "----------------------------------------------" << std::endl << std::endl;
        std::cout << "Wybierz co chcesz teraz zrobic:" << std::endl;
        std::cout << "1. Zarzadzaj klientami." << std::endl;
        std::cout << "2. Zarzadzaj posilkami." << std::endl;
        std::cout << "3. Zarzadzaj wynajmem." << std::endl;
        std::cout << "4. Zarzadzaj pokojami." << std::endl;
        std::cout << "5. Zapisz stan aplikacji do pliku." << std::endl;
        std::cout << "6. Zakoncz dzialanie programu." << std::endl << std::endl;

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice)
        {
            case '1':
                client();
                break;
            case '2':
                meal();
                break;
            case '3':
                rent();
                break;
            case '4':
                room();
                break;
            case '5':
            {
                saveAppState("stan_aplikacji.txt");
                break;
            }
            case '6':
                menuExit = true;
                break;
            default:
                std::cout << "Wybrano zla opcje." << std::endl;
                break;
        }
    }
}

void Menu::client()
{
    bool clientExit = false;
    char clientChoice;

    while(!clientExit)
    {
        std::cout << "1. Zarejestruj klienta." << std::endl;
        std::cout << "2. Wyrejestruj klienta." << std::endl;
        std::cout << "3. Wyswietl informacje o kliencie." << std::endl;
        std::cout << "4. Wyswietl informacje o wszystkich klientach." << std::endl;
        std::cout << "5. Powrot do menu." << std::endl;
        std::cout << "6. Zakoncz dzialanie programu." << std::endl;

        std::cin >> clientChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(clientChoice)
        {
            case '1':
            {
                std::string firstName, lastName, personalID;
                std::cout << "Podaj imie klienta: ";
                getline(std::cin, firstName);
                std::cout << "Podaj nazwisko klienta: ";
                getline(std::cin, lastName);
                std::cout << "Podaj numer pesel klienta: ";
                std::cin >> personalID;

                std::string city, street, number;
                std::cout << "Podaj miasto zamieszkania klienta: ";
                std::cin.ignore();
                getline(std::cin, city);
                std::cout << "Podaj ulice zamieszkania klienta: ";
                getline(std::cin, street);
                std::cout << "Podaj numer ulicy: ";
                getline(std::cin, number);

                try
                {
                    clientManager->registerClient(firstName, lastName, personalID, std::make_shared<Address>(city, street, number));
                }
                catch(ParameterException &error)
                {
                    std::cerr << "Blad parametru: " << error.what() << std::endl;
                }
                catch(LogicException &error)
                {
                    std::cerr << "Blad logiczny: " << error.what() << std::endl;
                }
                break;
            }
            case '2':
            {
                std::string personalID;
                std::cout << "Podaj numer pesel klienta: ";
                std::cin >> personalID;

                try
                {
                    ClientPtr client = clientManager->getClient(personalID);

                    if(client == nullptr)
                    {
                        std::cout << "Klient o podanym numerze pesel nie istnieje." << std::endl;
                        break;
                    }

                    clientManager->unregisterClient(client);
                }
                catch(ParameterException &error)
                {
                    std::cerr << "Blad parametru: " << error.what() << std::endl;
                }
                catch(LogicException &error)
                {
                    std::cerr << "Blad logiczny: " << error.what() << std::endl;
                }
                break;
            }
            case '3':
            {
                std::string personalID;
                std::cout << "Podaj numer pesel klienta: ";
                std::cin >> personalID;

                ClientPtr client = clientManager->getClient(personalID);
                if(client == nullptr)
                {
                    std::cout << "Podany klient nie istnieje." << std::endl;
                    break;
                }

                std::cout << client->getInfo() << std::endl;
                break;
            }
            case '4':
            {
                std::cout << clientManager->getAllClientsReport() << std::endl;
                break;
            }
            case '5':
            {
                clientExit = true;
                break;
            }
            case '6':
                exit(0);
                break;
            default:
                std::cout << "Wybrano zla opcje." << std::endl;
                break;
        }
    }
}

void Menu::meal()
{
    bool mealExit = false;
    char mealChoice;

    while(!mealExit)
    {
        std::cout << "1. Zamow posilek." << std::endl;
        std::cout << "2. Wyswietl informacje o wszystkich posilkach." << std::endl;
        std::cout << "3. Powrot do menu." << std::endl;
        std::cout << "4. Zakoncz dzialanie programu." << std::endl;

        std::cin >> mealChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(mealChoice)
        {
            case '1':
            {
                std::string mealName;
                std::cout << "Podaj nazwe posilku: ";
                getline(std::cin, mealName);

                try
                {
                    mealManager->orderMeal(mealName);
                }
                catch(ParameterException &error)
                {
                    std::cerr << "Blad parametru: " << error.what() << std::endl;
                }
                catch(LogicException &error)
                {
                    std::cerr << "Blad logiczny: " << error.what() << std::endl;
                }
                break;
            }
            case '2':
            {
                std::cout << mealManager->getAllMeals() << std::endl;
                break;
            }
            case '3':
                mealExit = true;
                break;
            case '4':
                exit(0);
                break;
            default:
                std::cout << "Wybrano zla opcje." << std::endl;
                break;
        }
    }
}

void Menu::rent()
{
    bool rentExit = false;
    char rentChoice;

    while(!rentExit)
    {
        std::cout << "1. Wynajmij pokoj." << std::endl;
        std::cout << "2. Zakoncz wynajem." << std::endl;
        std::cout << "3. Wyswietl informacje o wynajmie." << std::endl;
        std::cout << "4. Wyswietl informacje o wszytskich aktualnych wynajmach." << std::endl;
        std::cout << "5. Wyswietl informacje o wszystkich archiwalnych wynajmach." << std::endl;
        std::cout << "6. Powrot do menu." << std::endl;
        std::cout << "7. Zakoncz dzialanie programu." << std::endl;

        std::cin >> rentChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (rentChoice)
        {
            case '1':
            {
                std::string personalID;
                int basePrice, roomCapacity;
                std::cout << "Podaj numer pesel klienta: ";
                std::cin >> personalID;

                ClientPtr client = clientManager->getClient(personalID);
                if(client == nullptr)
                {
                    std::cout << "Podany klient nie istnieje." << std::endl;
                    break;
                }

                std::cout << "Podaj cene za pokoj: ";
                std::cin >> basePrice;
                std::cout << "Podaj pojemnosc pokoju: ";
                std::cin >> roomCapacity;

                RoomPtr room = roomManager->getRoom(basePrice, roomCapacity);
                if(room == nullptr)
                {
                    std::cout << "Nie znaleziono odpowiedniego pokoju." << std::endl;
                    break;
                }

                try
                {
                    rentManager->rentRoom(client, room);
                }
                catch(ParameterException &error)
                {
                    std::cerr << "Blad parametru: " << error.what() << std::endl;
                }
                catch(LogicException &error)
                {
                    std::cerr << "Blad logiczny: " << error.what() << std::endl;
                }
                break;
            }
            case '2':
            {
                int roomNumber;
                std::cout << "Podaj numer pokoju: ";
                std::cin >> roomNumber;

                try
                {
                    rentManager->returnRoom(roomManager->getRoom(roomNumber));
                }
                catch(ParameterException &error)
                {
                    std::cerr << "Blad parametru: " << error.what() << std::endl;
                }
                catch(LogicException &error)
                {
                    std::cerr << "Blad logiczny: " << error.what() << std::endl;
                }
                break;
            }
            case '3':
            {
                int roomNumber;
                std::cout << "Podaj numer pokoju: ";
                std::cin >> roomNumber;

                RentPtr rent = rentManager->getRent(roomManager->getRoom(roomNumber));
                if(rent == nullptr)
                {
                    std::cout << "Nie znaleziono wynajmu." << std::endl;
                    break;
                }

                std::cout << rent->getInfo() << std::endl;
                break;
            }
            case '4':
            {
                std::cout << rentManager->getAllCurrentRents() << std::endl;
                break;
            }
            case '5':
            {
                std::cout << rentManager->getAllArchiveRents() << std::endl;
                break;
            }
            case '6':
            {
                rentExit = true;
                break;
            }
            case '7':
            {
                exit(0);
                break;
            }
            default:
                std::cout << "Wybrano zla opcje." << std::endl;
                break;
        }
    }
}

void Menu::room()
{
    bool roomExit = false;
    char roomChoice;

    while(!roomExit)
    {
        std::cout << "1. Zarejestruj pokoj." << std::endl;
        std::cout << "2. Wyrejestruj pokoj." << std::endl;
        std::cout << "3. Wyswietl informacje o pokoju." << std::endl;
        std::cout << "4. Wyswietl informacje o wszystkich pokojach." << std::endl;
        std::cout << "5. Powrot do menu." << std::endl;
        std::cout << "6. Zakoncz dzialanie programu." << std::endl;

        std::cin >> roomChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (roomChoice)
        {
            case '1':
            {
                int basePrice, roomNumber, roomCapacity;
                std::cout << "Podaj cene: ";
                std::cin >> basePrice;
                std::cout << "Podaj numer pokoju: ";
                std::cin >> roomNumber;
                std::cout << "Podaj pojemnosc pokoju: ";
                std::cin >> roomCapacity;

                try
                {
                    RoomPtr room = roomManager->registerRoom(basePrice, roomNumber, roomCapacity);
                }
                catch(ParameterException &error)
                {
                    std::cerr << "Blad parametru: " << error.what() << std::endl;
                }
                catch(LogicException &error)
                {
                    std::cerr << "Blad logiczny: " << error.what() << std::endl;
                }
                break;
            }
            case '2':
            {
                int roomNumber;
                std::cout << "Podaj numer pokoju: ";
                std::cin >> roomNumber;

                try
                {
                    roomManager->unregisterRoom(roomManager->getRoom(roomNumber));
                }
                catch(ParameterException &error)
                {
                    std::cerr << "Blad parametru: " << error.what() << std::endl;
                }
                catch(LogicException &error)
                {
                    std::cerr << "Blad logiczny: " << error.what() << std::endl;
                }
                break;
            }
            case '3':
            {
                int roomNumber;
                std::cout << "Podaj numer pokoju: ";
                std::cin >> roomNumber;

                RoomPtr room = roomManager->getRoom(roomNumber);
                if(room == nullptr)
                {
                    std::cout << "Pokoj o podanym numerze nie istnieje." << std::endl;
                    break;
                }

                std::cout << room->getInfo() << std::endl;
                break;
            }
            case '4':
                std::cout << roomManager->getAllRooms() << std::endl;
                break;
            case '5':
                roomExit = true;
                break;
            case '6':
                exit(0);
                break;
            default:
                std::cout << "Wybrano zla opcje." << std::endl;
                break;
        }
    }
}

void Menu::saveAppState(const std::string &fileName)
{
    std::string clientInfo = clientManager->getAllClientsReport();
    std::string mealInfo = mealManager->getAllMeals();
    std::string currentRentsInfo = rentManager->getAllCurrentRents();
    std::string archiveRentsInfo = rentManager->getAllArchiveRents();
    std::string roomInfo = roomManager->getAllRooms();

    std::ofstream file(fileName);
    if(file.is_open())
    {
        file << clientInfo << std::endl << mealInfo << std::endl << currentRentsInfo << std::endl
            << archiveRentsInfo << std::endl << roomInfo << std::endl;
        file.close();
    }
    else
    {
        std::cout << "Nie mozna otworzyc pliku " << fileName << "." << std::endl;
    }
}