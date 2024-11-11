//
// Created by deald on 10/27/2024.
//
#include "map.h"
#include "hazard.h"
#include <iostream>
using namespace std;

void Riptide::trigger(Map &map, Player &player) {
  Room *new_room = map.get_random_room();
  while (!(new_room->isEdge())) {
    new_room = map.get_random_room();
  }
  player.setRoom(new_room);
  cout << "A riptide dragged you to an edge..." << endl;
}

void Whirlpool::trigger(Map &map, Player &player) {
  Room *new_room = map.get_random_room();
  player.setRoom(new_room);
  cout << "The whirlpool threw you somewhere..." << endl;
}
