//
// Created by deald on 10/27/2024.
//
// Contains rooms
#ifndef MAP_H
#define MAP_H

#include "player.h"
#include "Room.h"

class Map {
public:
  Map(Player *player);
  void display() const;
private:
  Room *first_room;
  Room *rooms[30];
  Room *get_random_room() const;
};

#endif //MAP_H
