cmake_minimum_required(VERSION 3.29)
project(Wumpus)

set(CMAKE_CXX_STANDARD 20)

add_executable(Wumpus main.cpp
        Room.cpp
        Kracken.cpp
        Map.cpp
        Hazard.cpp
        Innards.cpp
        Player.cpp
)
