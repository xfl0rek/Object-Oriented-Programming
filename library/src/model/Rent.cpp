#include "model/Rent.h"
#include <sstream>
#include "exceptions/ParameterException.h"
#include "exceptions/LogicException.h"

Rent::Rent(const boost::uuids::uuid &id, const ClientPtr &client, const RoomPtr &room,
           const pt::ptime &beginTime) : id(id), client(client), room(room), beginTime(beginTime) {

    if(beginTime == pt::not_a_date_time)
    {
        Rent::beginTime = pt::second_clock::local_time();
    }

    endTime = pt::not_a_date_time;
    rentCost = 0;

    if (client == nullptr) { throw ParameterException("Nie mozna dokonac rezerwacji bez wyboru klienta."); }
    if (room == nullptr) { throw ParameterException("Nie mozna dokonac rezerwacji bez wyboru pokoju."); }
}

Rent::~Rent() {}

const boost::uuids::uuid &Rent::getID() const
{
    return id;
}

const pt::ptime &Rent::getBeginTime() const
{
    return beginTime;
}

const pt::ptime &Rent::getEndTime() const
{
    return endTime;
}

double Rent::getRentCost() const
{
    return rentCost;
}

const ClientPtr &Rent::getClient() const
{
    return client;
}

const RoomPtr &Rent::getRoom() const
{
    return room;
}

std::string Rent::getInfo() const
{
    std::stringstream rentData;
    rentData << "Identyfikator wypozyczenia: " << id << std::endl << std::endl
    << "Klient: " << std::endl << getClient()->getInfo() << std::endl << std::endl
    << "Pokoj: " << std::endl << getRoom()->getInfo() << std::endl << std::endl
    << "Czas wynajecia: " << beginTime << ", koniec wynajmu: " << endTime << std::endl
    << "Ostateczna cena: " << getRentCost();
    return rentData.str();
}

void Rent::endRent(const pt::ptime &endTimeStatus)
{
    if(endTime == pt::not_a_date_time)
    {
        if(endTimeStatus == pt::not_a_date_time)
        {
            endTime = pt::second_clock::local_time();
        }
        else
        {
            if(endTimeStatus > beginTime)
            {
                endTime = endTimeStatus;
            }
            else
            {
                endTime = beginTime;
            }
        }
        rentCost = calculateRentCost();
    }
}

unsigned int Rent::getRentDays() const
{
    unsigned int days;
    pt::time_period period = pt::time_period(beginTime, endTime);
    days = period.length().hours() / 24;

    if(period.length().hours() % 24 >= 1)
    {
        days++;
    }

    return days;
}

double Rent::calculateRentCost() const
{
    double cost = round(100 * getClient()->calculateClientDiscount(getRentDays() * (getRoom()->getBasePrice()))) / 100;

    if(cost < 0)
    {
        throw LogicException("Niepoprawa wartosc ceny koncowej!");
    }

    return cost;
}