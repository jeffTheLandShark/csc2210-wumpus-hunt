//
// Created by deald on 10/27/2024.
//

#include "Map.h"

#include <iostream>

#include "Kracken.h"
using namespace std;

Map::Map() {
  *rooms = new Room[30];
  for(auto & room : rooms) {
    room = new Room();
    room->setInnard(new Innards('.')); //TODO fix this
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

  //TODO make it random and based on actual innards
  rooms[1]->setInnard(new Innards('@'));
  rooms[5]->setInnard(new Innards('!'));
  rooms[10]->setInnard(new Innards('>'));
  rooms[14]->setInnard(new Innards('#'));
  rooms[17]->setInnard(new Innards('>'));
  rooms[20]->setInnard(new Innards('!'));
  rooms[25]->setInnard(new Innards('>'));
  rooms[29]->setInnard(new Innards('+'));
  rooms[8]->setInnard(new Innards('?'));
}

void Map::display() const {
  for(int i = 0; i < 30; i++) {
    rooms[i]->display();
    if(i % 6 == 5) {
      cout << endl;
    }
  }
}
