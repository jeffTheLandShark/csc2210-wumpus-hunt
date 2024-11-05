//
// Created by deald on 10/27/2024.
//

#include "Room.h"

#include <iostream>

Room::Room() {
  north = nullptr;
  south = nullptr;
  east = nullptr;
  west = nullptr;
  innard = nullptr;
}

void Room::setNorth(Room *room) {
  north = room;
}

void Room::setSouth(Room *room) {
  south = room;
}

void Room::setEast(Room *room) {
  east = room;
}

void Room::setWest(Room *room) {
  west = room;
}

Room Room::getNorth() const {
  return *north;
}

Room Room::getSouth() const {
  return *south;
}

Room Room::getEast() const {
  return *east;
}

Room Room::getWest() const {
  return *west;
}

void Room::setInnard(Innards *innard) {
  this->innard = innard;
}

Innards *Room::getInnard() const {
  return &*innard;
}

bool Room::hasKraken() const {
  return innard->getSymbol() == '#';
}

void Room::display() const {
  if (innard) {
    innard->display();
  } else {
    std::cout << ".";
  }
}
