cmake_minimum_required(VERSION 3.29)
project(Wumpus)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wumpus main.cpp
        Room.cpp
        Room.h
        Kracken.cpp
        Kracken.h
        Map.cpp
        Map.h
        Item.h
        Hazard.cpp
        Hazard.h
        Innards.cpp
        Innards.h
        Player.cpp
        Player.h
)
