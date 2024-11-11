cmake_minimum_required(VERSION 3.29)
project(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(src main.cpp
        room.cpp
        kraken.cpp
        map.cpp
        hazard.cpp
        innards.cpp
        player.cpp
        items.cpp
)
