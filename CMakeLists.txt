cmake_minimum_required(VERSION 3.17)
project(RRH_Labo3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(RRH_Labo3 main.cpp calendrier.cpp calendrier.h)