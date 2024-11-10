//
// Created by deald on 10/27/2024.
//
#include "map.h"
#include "hazard.h"


void Riptide::trigger(Map map, Player& player) {
  Room *new_room = map.get_random_room();
  while (!(new_room->isEdge())) {
    new_room = map.get_random_room();
  }
  player.setRoom(new_room);
}

void Whirlpool::trigger(Map map, Player& player) {
  Room *new_room = map.get_random_room();
  player.setRoom(new_room);
}
