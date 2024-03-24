#include <boost/test/unit_test.hpp>
#include "model/Rent.h"
#include "typedefs.h"
#include "model/Client.h"
#include "model/Room.h"
#include "model/Address.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentFixture
{
    const std::string testFirstName = "Daniel";
    const std::string testLastName = "Magiczny";
    const std::string testPersonalID = "12345678912";
    const unsigned int testBasePrice = 1000;
    const unsigned int testRoomNumber = 50;
    const unsigned int testRoomCapacity = 2;
    ClientPtr testClient;
    AddressPtr testAddress;
    RoomPtr testRoom;
    boost::uuids::uuid testID;
    pt::ptime testBeginTime;

    TestSuiteRentFixture()
    {
        testAddress = std::make_shared<Address>("Torun", "Urzednicza", "2");
        testClient = std::make_shared<Client>(testFirstName, testLastName, testPersonalID, testAddress);
        testRoom = std::make_shared<Room>(testBasePrice, testRoomNumber, testRoomCapacity);
        boost::uuids::random_generator generator;
        testID = generator();
        testBeginTime = pt::second_clock::local_time();
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent, TestSuiteRentFixture)

BOOST_AUTO_TEST_CASE(ConstructorTest)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    BOOST_TEST(rent.getID() == testID);
    BOOST_TEST(rent.getClient() == testClient);
    BOOST_TEST(rent.getRoom() == testRoom);
    BOOST_TEST(rent.getBeginTime() == testBeginTime);
    BOOST_TEST(rent.getEndTime().is_not_a_date_time());
    BOOST_TEST(rent.getRentCost() == 0);
}

BOOST_AUTO_TEST_CASE(ParameterConstructorTestDefaultBeginTime)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    BOOST_TEST_REQUIRE(!rent.getBeginTime().is_not_a_date_time());
    pt::ptime now = pt::second_clock::local_time();
    pt::time_period period = pt::time_period(rent.getBeginTime(), now);
    BOOST_TEST((period.length().hours() == 0 && period.length().minutes() == 0));
}

BOOST_AUTO_TEST_CASE(EndRentTestEndNow)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    rent.endRent(testBeginTime);
    pt::time_period period = pt::time_period(rent.getEndTime(), testBeginTime);
    BOOST_TEST(rent.getEndTime() == testBeginTime);
}

BOOST_AUTO_TEST_CASE(EndRentTestInFuture)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    pt::ptime future = testBeginTime + pt::hours(5);
    rent.endRent(future);

    pt::time_period period = pt::time_period(rent.getEndTime(), future);
    BOOST_TEST(rent.getEndTime() == future);
}

BOOST_AUTO_TEST_CASE(EndRentTestInPast)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    pt::ptime past = testBeginTime - pt::hours(5);
    rent.endRent(past);
    BOOST_TEST(rent.getEndTime() == rent.getBeginTime());
}

BOOST_AUTO_TEST_CASE(EndRentTestAlreadyEnded)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    rent.endRent(testBeginTime);
    pt::ptime future = testBeginTime + pt::hours(5);
    rent.endRent(future);
    BOOST_TEST(rent.getEndTime() == testBeginTime);
}

BOOST_AUTO_TEST_CASE(getRentDaysTestAfter5hours)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    pt::ptime future = testBeginTime + pt::hours(5);
    rent.endRent(future);
    BOOST_TEST(rent.getRentDays() == 1);
}

BOOST_AUTO_TEST_CASE(getRentDaysTestAfter30minutes)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    pt::ptime future = testBeginTime + pt::minutes(30);
    rent.endRent(future);
    BOOST_TEST(rent.getRentDays() == 0);
}

BOOST_AUTO_TEST_CASE(calculateRentCostTestAfter0Days)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    rent.endRent(testBeginTime);
    BOOST_TEST(rent.getRentCost() == 0);
}

BOOST_AUTO_TEST_CASE(calculateRentCostTest)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    pt::ptime future = testBeginTime + pt::hours(5);
    rent.endRent(future);
    BOOST_TEST(rent.getRentCost() == 1000);
}

BOOST_AUTO_TEST_CASE(RentCostTestPermanentCost)
{
    Rent rent(testID, testClient, testRoom, testBeginTime);
    pt::ptime future = testBeginTime + pt::hours(5);
    rent.endRent(future);
    double before = rent.getRentCost();
    rent.getRoom()->setBasePrice(500);
    double after = rent.getRentCost();
    BOOST_TEST(before == after);
}

BOOST_AUTO_TEST_SUITE_END()