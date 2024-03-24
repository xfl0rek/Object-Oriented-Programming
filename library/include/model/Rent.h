#ifndef RENT_H
#define RENT_H

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "boost/date_time.hpp"
#include "model/Client.h"
#include "model/Room.h"
#include "typedefs.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Rent
{
private:
    const boost::uuids::uuid id;
    pt::ptime beginTime;
    pt::ptime endTime;
    double rentCost;
    const ClientPtr client;
    const RoomPtr room;

public:
    Rent(const boost::uuids::uuid &id, const ClientPtr &client, const RoomPtr &room, const pt::ptime &beginTime = pt::not_a_date_time);
    ~Rent();

    const boost::uuids::uuid &getID() const;
    const pt::ptime &getBeginTime() const;
    const pt::ptime &getEndTime() const;
    double getRentCost() const;
    const ClientPtr &getClient() const;
    const RoomPtr &getRoom() const;

    std::string getInfo() const;

    void endRent(const pt::ptime &endTimeStatus);
    unsigned int getRentDays() const;
    double calculateRentCost() const;
};

#endif
