cmake_minimum_required(VERSION 3.17)
project(student)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")
add_executable(student main.cpp student.cpp student.h grupa.cpp grupa.h licenta.cpp licenta.h rlutil.h strategy.cpp)