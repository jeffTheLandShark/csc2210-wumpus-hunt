//
// Created by deald on 10/27/2024.
//

#include "Room.h"
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