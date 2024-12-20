/**
 * map.cpp
 * This file contains the implementation of the Map class.
 */

#include "map.h"


#include <iostream>
#include <random>

#include "hazard.h"
#include "items.h"
#include "kraken.h"
#include "player.h"
#include "room.h"

using namespace std;

Map::Map(Player *player) {
  *rooms = new Room[30];
  for (auto &room : rooms) {
    room = new Room();
    room->setInnard(new Innards());
  }
  // directional pointer setter for rooms
  for (int i = 0; i < 30; i++) {
    if (i > 5) {
      rooms[i]->setNorth(rooms[i - 6]);
    }
    if (i < 24) {
      rooms[i]->setSouth(rooms[i + 6]);
    }
    if ((i + 1) % 6 != 0) {
      rooms[i]->setEast(rooms[i + 1]);
    }
    if (i % 6 != 0) {
      rooms[i]->setWest(rooms[i - 1]);
    }
  }
  first_room = rooms[0];
  Room *random_room = get_random_room();
  random_room->setInnard(new Kraken());

  // sets custom innards of room while that room doesn't have anything in it.
  while (random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  random_room->setInnard(new Whirlpool());
  for (int i = 0; i < 2; i++) {
    while (random_room->getInnard()->getSymbol() != '.') {
      random_room = get_random_room();
    }
    random_room->setInnard(new Riptide());
  }
  while (random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  random_room->setInnard(new AirTank());
  for (int i = 0; i < 2; i++) {
    while (random_room->getInnard()->getSymbol() != '.') {
      random_room = get_random_room();
    }
    random_room->setInnard(new Harpoon());
  }
  while (random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  random_room->setInnard(new Net());
  while (random_room->getInnard()->getSymbol() != '.') {
    random_room = get_random_room();
  }
  player->setRoom(random_room);
  game_over = false;
  win = false;
}

void Map::display(const Room *playerRoom) const {
  for (int i = 0; i < 30; i++) {
    if (rooms[i] == playerRoom) {
      cout << "+";
    } else {
      rooms[i]->display();
    }
    if (i % 6 == 5) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

Room *Map::get_random_room() const {
  srand(time(nullptr));
  Room *current_room = first_room;
  int move = rand() % 6;
  for (int i = 0; i < move; i++) {
    current_room = current_room->getEast();
  }
  move = rand() % 5;
  for (int i = 0; i < move; i++) {
    current_room = current_room->getSouth();
  }
  return current_room;
}

bool Map::is_over() const { return game_over; }

bool Map::is_win() const { return win; }

void Map::set_game_over(bool over) { game_over = over; }

void Map::set_win(bool win) { this->win = win; }

bool Map::roomExists(Room *room, char dir) {
  // checks if room exists in the given direction
  switch (dir) {
  case 'n':
    return room->getNorth() != nullptr;
  case 'e':
    return room->getEast() != nullptr;
  case 's':
    return room->getSouth() != nullptr;
  case 'w':
    return room->getWest() != nullptr;
  default:
    cout << "Unknown direction" << endl;
    return false;
  }
}

Map::~Map() {
  for (const Room *room : rooms) {
    delete room;
  }
}