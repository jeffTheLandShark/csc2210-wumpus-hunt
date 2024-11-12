/*
 * hazard.cpp
 * @brief Hazards are special innards that can move the player to a different room.
 */

#include "hazard.h"

#include <iostream>

#include "map.h"
#include "player.h"
#include "room.h"


// Riptide triggers when the player enters the room - moves the player to a random edge room.
void Riptide::trigger(Map &map, Player &player) {
  Room *new_room = map.get_random_room();
  while (!(new_room->isEdge())) {
    new_room = map.get_random_room();
  }
  player.setRoom(new_room);
  std::cout << "A riptide dragged you to an edge..." << std::endl;
  player.addAir(-airLoss);
}

// Whirlpool triggers when the player enters the room - moves the player to a random room.
void Whirlpool::trigger(Map &map, Player &player) {
  Room *new_room = map.get_random_room();
  player.setRoom(new_room);
  std::cout << "The whirlpool threw you somewhere..." << std::endl;
  player.addAir(-airLoss);
}
