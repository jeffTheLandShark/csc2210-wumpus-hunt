//
// Created by deald on 10/27/2024.
//

#include "map.h"
#include <iostream>

#include "hazard.h"
#include "items.h"
#include "kraken.h"
using namespace std;

Map::Map(Player *player) {
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
      rooms[i]->setWest(rooms[i] + 1);
    }
  }
  first_room = rooms[0];
  Room *random_room = get_random_room();
  random_room->setInnard(new Kraken());
  while(random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  random_room->setInnard(new Whirlpool());
  for(int i = 0; i < 2; i++) {
    while(random_room->getInnard()->getSymbol() != '.') {
      random_room = get_random_room();
    }
    random_room->setInnard(new Riptide());
  }
  while(random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  random_room->setInnard(new AirTank());
  for(int i = 0; i < 2; i++) {
    while(random_room->getInnard()->getSymbol() != '.') {
      random_room = get_random_room();
    }
    random_room->setInnard(new Harpoon());
  }
  while(random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  random_room->setInnard(new Net());
  while(random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  random_room->setInnard(player);
}
void Map::display() const {
  for(int i = 0; i < 30; i++) {
    rooms[i]->display();
    if(i % 6 == 5) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}
Room *Map::get_random_room() const {
  Room *current_room = first_room;
  int move = rand() % 6;
  for(int i = 0; i < move; i++) {
    *current_room = current_room->getEast();
  }
  move = rand() % 5;
  for(int i = 0; i < move; i++) {
    *current_room = current_room->getSouth();
  }
  return current_room;
}
