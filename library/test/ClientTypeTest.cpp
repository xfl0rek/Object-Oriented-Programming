#include <boost/test/unit_test.hpp>
#include "model/ClientType.h"
#include "model/Default.h"
#include "model/Premium.h"
#include "typedefs.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClientType)

BOOST_AUTO_TEST_CASE(applyDiscountTest)
{
    ClientTypePtr clientType = std::make_shared<Default>();
    BOOST_TEST(clientType->applyDiscount(1000) == 1000);

    clientType = std::make_shared<Premium>();
    BOOST_TEST(clientType->applyDiscount(1000) == 500);
}

BOOST_AUTO_TEST_CASE(getInfoTest)
{
    ClientTypePtr clientType = std::make_shared<Default>();
    BOOST_TEST(clientType->getInfo() == "default");

    clientType = std::make_shared<Premium>();
    BOOST_TEST(clientType->getInfo() == "premium");
}

BOOST_AUTO_TEST_SUITE_END()