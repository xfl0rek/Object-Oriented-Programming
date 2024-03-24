#include <boost/test/unit_test.hpp>
#include "model/Address.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteAddress)

BOOST_AUTO_TEST_CASE(ConstructorTest)
{
    std::string city = "Torun";
    std::string street = "Urzednicza";
    std::string number = "2";
    AddressPtr address(new Address(city, street, number));
    BOOST_TEST(address->getCity() == city);
    BOOST_TEST(address->getStreet() == street);
    BOOST_TEST(address->getNumber() == number);
}

BOOST_AUTO_TEST_CASE(setCityTest)
{
    AddressPtr address(new Address("Lodz", "Piotrkowska", "100"));
    address->setCity("Pabianice");
    BOOST_TEST(address->getCity() == "Pabianice");
    address->setCity("");
    BOOST_TEST(address->getCity() == "Pabianice");
}

BOOST_AUTO_TEST_CASE(setStreetTest)
{
    AddressPtr address(new Address("Lodz", "Piotrkowska", "100"));
    address->setStreet("Zgierska");
    BOOST_TEST(address->getStreet() == "Zgierska");
    address->setStreet("");
    BOOST_TEST(address->getStreet() == "Zgierska");
}

BOOST_AUTO_TEST_CASE(setNumberTest)
{
    AddressPtr address(new Address("Lodz", "Piotrkowska", "100"));
    address->setNumber("50");
    BOOST_TEST(address->getNumber() == "50");
    address->setNumber("");
    BOOST_TEST(address->getNumber() == "50");
}

BOOST_AUTO_TEST_CASE(getInfoTest)
{
    AddressPtr address(new Address("Lodz", "Piotrkowska", "100"));
    BOOST_TEST(address->getInfo() == "miasto: Lodz, ulica i numer ulicy: Piotrkowska 100\n");
}

BOOST_AUTO_TEST_SUITE_END()