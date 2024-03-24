#include <boost/test/unit_test.hpp>
#include "model/Room.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteRoom)

BOOST_AUTO_TEST_CASE(ConstructorTest)
{
    RoomPtr room(new Room(100, 1, 2));
    BOOST_TEST(room->getBasePrice() == 100);
    BOOST_TEST(room->getRoomNumber() == 1);
    BOOST_TEST(room->getRoomCapacity() == 2);
}

BOOST_AUTO_TEST_CASE(setBasePriceTest)
{
    RoomPtr room(new Room(100, 1, 2));
    room->setBasePrice(200);
    BOOST_TEST(room->getBasePrice() == 200);
    room->setBasePrice(-1000);
    BOOST_TEST(room->getBasePrice() == 200);
}

BOOST_AUTO_TEST_CASE(setArchiveTest)
{
    RoomPtr room(new Room(100, 1, 2));
    room->setArchive(true);
    BOOST_TEST(room->isArchived() == true);
}

BOOST_AUTO_TEST_CASE(getInfoTest)
{
    RoomPtr room(new Room(100, 1, 2));
    BOOST_TEST(room->getInfo() == "Cena za pokoj: 100\nNumer pokoju: 1\nPojemnosc pokoju: 2\n");
}

BOOST_AUTO_TEST_SUITE_END()