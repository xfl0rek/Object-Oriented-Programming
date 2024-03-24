cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
    include/model/Client.h
    src/model/Client.cpp
    include/model/Address.h
    include/model/ClientType.h
    include/model/Default.h
    include/model/Premium.h
    include/typedefs.h
    src/model/Address.cpp
    src/model/Default.cpp
    src/model/Premium.cpp
    include/model/Room.h
    include/model/Rent.h
    src/model/Room.cpp
    src/model/Rent.cpp
    src/model/Meal.cpp
    include/model/Meal.h
    include/repositories/Repository.h
    src/repositories/Repository.cpp
    include/managers/ClientManager.h
    include/managers/RentManager.h
    include/managers/RoomManager.h
    include/managers/MealManager.h
    src/managers/ClientManager.cpp
    src/managers/RentManager.cpp
    src/managers/RoomManager.cpp
    src/managers/MealManager.cpp
    include/exceptions/LogicException.h
    include/exceptions/ParameterException.h
    include/menu/Menu.h
    src/menu/Menu.cpp
)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES # tu w przyszłości będą dodawane pliki źródłowe testów
    test/master.cpp
    test/ClientTest.cpp
    test/AddressTest.cpp
    test/ClientTypeTest.cpp
    test/RentTest.cpp
    test/RoomTest.cpp
    test/RepositoryTest.cpp
    test/RentManagerTest.cpp
    test/ClientManagerTest.cpp
    test/RoomManagerTest.cpp
    test/MealTest.cpp
    test/MealManagerTest.cpp
)

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
