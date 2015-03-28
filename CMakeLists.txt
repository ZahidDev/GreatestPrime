cmake_minimum_required(VERSION 3.1)
project(GreatestPrime)
set(SOURCE_FILES src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)

set(BOOST_INCLUDEDIR "C:/Libs/boost_1_57_0")
set(BOOST_LIBRARYDIR "C:/Libs/boost_1_57_0/lib")

include_directories(${BOOST_INCLUDEDIR})
find_package(Boost 1.57.0 COMPONENTS system chrono REQUIRED)

add_executable(GreatestPrime ${SOURCE_FILES} src/isPrime.h src/isPrime.cpp src/LargestPrime.h src/LargestPrime.cpp)
target_link_libraries(GreatestPrime ${Boost_LIBRARIES})
set(CMAKE_RUNTIME_OUTPUT_DIRE   CTORY "C:/Users/Zahidul/Google Drive/Code/ClionProjects/Binaries")


