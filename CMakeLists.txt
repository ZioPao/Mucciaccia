cmake_minimum_required(VERSION 3.13)
project(pail)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pail
        library.cpp
        library.h character.cpp character.h game.cpp game.h)
