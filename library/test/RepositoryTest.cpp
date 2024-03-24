#include <boost/test/unit_test.hpp>
#include "repositories/Repository.h"
#include "model/Client.h"
#include "model/Address.h"
#include "typedefs.h"

struct TestSuiteRepositoryFixture
{
    const std::string testFirstName = "Daniel";
    const std::string testLastName = "Magiczny";
    const std::string testPersonalID = "12345678912";
    AddressPtr testAddress;

    TestSuiteRepositoryFixture()
    {
        testAddress = std::make_shared<Address>("Torun", "Urzednicza", "2");
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRepository, TestSuiteRepositoryFixture)

BOOST_AUTO_TEST_CASE(GetTest)
{
    Repository<ClientPtr> clientRepository;
    int size = 9;
    ClientPtr clients[size];

    for(int i = 0; i < size; i++)
    {
        std::stringstream id;
        id << "1234567891" << i;
        clients[i] = std::make_shared<Client>(testFirstName, testLastName, id.str(), testAddress);
        clientRepository.add(clients[i]);
    }

    for(int i = 0; i < size; i++)
    {
        BOOST_TEST(clientRepository.get(i) == clients[i]);
    }
}

BOOST_AUTO_TEST_CASE(AddTest)
{
    Repository<ClientPtr> clientRepository;
    int size = 9;
    ClientPtr clients[size];

    for(int i = 0; i < size; i++)
    {
        std::stringstream id;
        id << "1234567891" << i;
        clientRepository.add(std::make_shared<Client>(testFirstName, testLastName, id.str(), testAddress));
    }

    BOOST_TEST(clientRepository.size() == size);
}

BOOST_AUTO_TEST_CASE(FindTest)
{
    Repository<ClientPtr> clientRepository;
    std::string findPersonalID = "";
    ClientPtr findClient = std::make_shared<Client>(testFirstName, testLastName, findPersonalID, testAddress);
    clientRepository.add(findClient);
    int size = 9;

    for(int i = 0; i < size; i++)
    {
        std::stringstream id;
        id << "1234567891" << i;
        clientRepository.add(std::make_shared<Client>(testFirstName, testLastName, id.str(), testAddress));
    }

    ClientPredicate predicate = [findPersonalID](const ClientPtr &find)
    {
        return find->getPersonalID() == findPersonalID;
    };

    BOOST_TEST(clientRepository.find(predicate) == findClient);
}

BOOST_AUTO_TEST_CASE(FindAllTest)
{
    Repository<ClientPtr> clientRepository;
    int size1 = 8;
    int size2 = 5;

    std::string findLastName = "Kiepski";
    BOOST_TEST_REQUIRE(testFirstName != findLastName);

    for(int i = 0; i < size1; i++)
    {
        std::stringstream id;
        id << "1234567891" << i;
        clientRepository.add(std::make_shared<Client>(testFirstName, findLastName, id.str(), testAddress));
    }
    for(int i = 0; i < size2; i++)
    {
        std::stringstream id;
        id << "1234567891" << i + size1;
        clientRepository.add(std::make_shared<Client>(testFirstName, testLastName, id.str(), testAddress));
    }

    ClientPredicate predicate = [findLastName](const ClientPtr &find)
    {
        return find->getLastName() == findLastName;
    };

    BOOST_TEST(clientRepository.findAll(predicate).size() == size1);
}

BOOST_AUTO_TEST_CASE(SizeTest)
{
    Repository<ClientPtr> clientRepository;
    int size = 9;
    for(int i = 0; i < size; i++)
    {
        std::stringstream id;
        id << "1234567891" << i;
        clientRepository.add(std::make_shared<Client>(testFirstName, testLastName, id.str(), testAddress));
    }

    BOOST_TEST(clientRepository.size() == size);
}

BOOST_AUTO_TEST_CASE(RemoveTest)
{
    Repository<ClientPtr> clientRepository;
    int size = 9;
    ClientPtr clients[size];
    for(int i = 0; i < size; i++)
    {
        std::stringstream id;
        id << "123456789" << i;
        clients[i] = std::make_shared<Client>(testFirstName, testLastName, id.str(), testAddress);
        clientRepository.add(clients[i]);
    }

    clientRepository.remove(clients[5]);
    clientRepository.remove(clients[2]);

    BOOST_TEST(clientRepository.size() == size - 2);
}

BOOST_AUTO_TEST_SUITE_END()