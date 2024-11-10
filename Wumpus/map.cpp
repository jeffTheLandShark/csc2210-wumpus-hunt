//
// Created by deald on 10/27/2024.
//

#include "map.h"
#include <iostream>
#include <random>
#include "hazard.h"
#include "items.h"
#include "kraken.h"
using namespace std;

Map::Map(Player *player) {
  *rooms = new Room[30];
  for(auto & room : rooms) {
    room = new Room();
    room->setInnard(new Innards());
  }
  for(int i = 0; i < 30; i++) {
    if(i > 5) {
      rooms[i]->setNorth(rooms[i - 6]);
    }
    if(i < 24) {
      rooms[i]->setSouth(rooms[i + 6]);
    }
    if(i+1 % 6 != 0) {
      rooms[i]->setEast(rooms[i+1]);
    }
    if(i % 6 != 0) {
      rooms[i]->setWest(rooms[i-1]);
    }
  }
  first_room = rooms[0];
  Room *random_room = get_random_room();
  random_room->setInnard(new Kraken('#'));

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
  player->setRoom(random_room);
  game_over = false;
  win = false;
}
void Map::display(const Room *playerRoom) const {
  for(int i = 0; i < 30; i++) {
    if(rooms[i] == playerRoom) {
      cout << "+";
    } else {
      rooms[i]->display();
    }
    if(i % 6 == 5) {
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
  for(int i = 0; i < move; i++) {
    current_room = current_room->getEast();
  }
  move = rand() % 5;
  for(int i = 0; i < move; i++) {
    current_room = current_room->getSouth();
  }
  return current_room;
}

bool Map::is_over() const {
  return game_over;
}
bool Map::is_win() const {
  return win;
}

void Map::set_game_over(const bool game_over) {
  this->game_over = game_over;
}
void Map::set_win(bool win) {
  this->win = win;
}
