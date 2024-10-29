//
// Created by deald on 10/27/2024.
//
// Contains rooms
#ifndef MAP_H
#define MAP_H

#include "Room.h"

class Map {
public:
  Map();
  void display();
private:
  Room *first_room;
};



#endif //MAP_H
