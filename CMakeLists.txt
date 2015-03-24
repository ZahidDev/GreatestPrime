cmake_minimum_required(VERSION 3.1)
project(GreatestPrime)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(SOURCE_FILES
    src/main.cpp)

add_executable(GreatestPrime ${SOURCE_FILES} src/isPrime.h src/isPrime.cpp src/largestPrime.h src/largestPrime.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Users/Zahidul/Google Drive/Code/ClionProjects/Binaries")