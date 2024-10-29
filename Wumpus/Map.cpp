//
// Created by deald on 10/27/2024.
//

#include "Map.h"

#include "Kracken.h"

Map::Map() {
  *rooms = new Room[30];
  for(auto & room : rooms) {
    room = new Room();
  }
  for(int i = 0; i < 30; i++) {
    if(i > 5) {
      rooms[i]->setNorth(rooms[i - 6]);
    }
    if(i < 24) {
      rooms[i]->setSouth(rooms[i + 6]);
    }
    if(i % 6 != 0) {
      rooms[i]->setEast(rooms[i] - 1);
    }
    if(i % 6 != 5) {
      rooms[i] ->setWest(rooms[i] + 1);
    }
  }
  first_room = rooms[0];

  rooms[1]->setInnard(new Innards('@'));
}

void Map::display() {
  for(int i = 0; i < 30; i++) {
    if(rooms[i]->getInnard() == nullptr)
  }
}
