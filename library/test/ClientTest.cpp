#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Default.h"
#include "model/Premium.h"
#include "typedefs.h"
#include <string>
#include "exceptions/ParameterException.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

BOOST_AUTO_TEST_CASE(ConstructorTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    std::string firstName = "Jan";
    std::string lastName = "Kowalski";
    std::string personalID = "12345678912";
    ClientPtr test(new Client(firstName, lastName, personalID, address));
    BOOST_TEST(test->getFirstName() == firstName);
    BOOST_TEST(test->getLastName() == lastName);
    BOOST_TEST(test->getPersonalID() == personalID);
    BOOST_TEST(test->getAddress() == address);
}

BOOST_AUTO_TEST_CASE(SetFirstNameTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    ClientPtr test(new Client("Jan", "Kowalski", "12345678912", address));
    test->setFirstName("Tomasz");
    BOOST_TEST(test->getFirstName() == "Tomasz");
    test->setFirstName("");
    BOOST_TEST(test->getFirstName() == "Tomasz");
}

BOOST_AUTO_TEST_CASE(SetLastNameTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    ClientPtr test(new Client("Jan", "Kowalski", "12345678912", address));
    test->setLastName("Freeman");
    BOOST_TEST(test->getLastName() == "Freeman");
    test->setLastName("");
    BOOST_TEST(test->getLastName() == "Freeman");
}

BOOST_AUTO_TEST_CASE(SetClientTypeTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    ClientPtr test(new Client("Jan", "Kowalski", "12345678912", address));
    ClientTypePtr premium = std::make_shared<Premium>();
    test->setClientType(premium);
    BOOST_TEST(test->getClientType() == premium);
    test->setClientType(nullptr);
    BOOST_TEST(test->getClientType() == premium);
}

BOOST_AUTO_TEST_CASE(SetAddressTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    ClientPtr test(new Client("Jan", "Kowalski", "12345678912", address));
    AddressPtr address2(new Address("Torun", "Urzednicza", "2"));
    test->setAddress(address2);
    BOOST_TEST(test->getAddress() == address2);
    test->setAddress(nullptr);
    BOOST_TEST(test->getAddress() == address2);
}

BOOST_AUTO_TEST_CASE(setArchiveTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    ClientPtr test(new Client("Jan", "Kowalski", "12345678912", address));
    test->setArchive(true);
    BOOST_TEST(test->isArchived() == true);
}

BOOST_AUTO_TEST_CASE(getInfoTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    ClientPtr test(new Client("Jan", "Kowalski", "12345678912", address));
    BOOST_TEST(test->getInfo() == "Imie i nazwisko: Jan Kowalski\nNumer pesel klienta: 12345678912\nTyp klienta: default\nCzy zarchiwizowany: false\nAdres zamieszkania klienta: miasto: Lodz, ulica i numer ulicy: Julianowska 12\n");
}

BOOST_AUTO_TEST_CASE(calculateClientDiscountTest)
{
    AddressPtr address(new Address("Lodz", "Julianowska", "12"));
    ClientPtr test(new Client("Jan", "Kowalski", "12345678912", address));
    double price = 10000;
    BOOST_TEST(test->calculateClientDiscount(price) == price);
    ClientTypePtr premium = std::make_shared<Premium>();
    test->setClientType(premium);
    BOOST_TEST(test->calculateClientDiscount(price) == 5000);
}

BOOST_AUTO_TEST_SUITE_END()