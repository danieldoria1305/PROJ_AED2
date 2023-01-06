
cmake_minimum_required(VERSION 3.10)
project(TrabalhoAED2)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(TrabalhoAED2 Code/src/Country.cpp Code/src/Airport.cpp Code/src/City.cpp Code/src/Flights.cpp Code/src/Airline.cpp Code/src/App.cpp Code/src/Gestao.cpp Code/tests/tests.cpp Code/tests/FlightGraphs.cpp Code/src/main.cpp)

target_link_libraries(TrabalhoAED2 gtest gtest_main)