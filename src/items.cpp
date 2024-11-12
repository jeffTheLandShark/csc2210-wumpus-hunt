/*
 * items.cpp
 * @brief The implementation of the Items class
 */

#include "items.h"

#include <iostream>

#include "map.h"
#include "player.h"
#include "room.h"

void Items::trigger(Map &map, Player &player) {
  pickup(player);
  player.getRoom()->setInnard(new Innards);
}

void AirTank::pickup(Player &player) {
  std::cout << "You find an airtank with " << air << " oxygen." << std::endl;
  player.addAir(air);
}

void Net::pickup(Player &player) {
  std::cout << "You find a net." << std::endl;
  player.addNet();
}

bool Net::use(Player &player, char direction) {
  if (Map::roomExists(player.getRoom(), direction)) {
    switch (direction) {
    case 'n': {
      Room *northRoom = player.getRoom()->getNorth();
      if (northRoom->hasKraken()) {
        return true;
      }
      if (Map::roomExists(northRoom, 'e') &&
          northRoom->getEast()->hasKraken()) {
        return true;
      }
      if (Map::roomExists(northRoom, 'w') &&
          northRoom->getWest()->hasKraken()) {
        return true;
      }
      return false;
    }
    case 'e': {
      Room *eastRoom = player.getRoom()->getEast();
      if (eastRoom->hasKraken()) {
        return true;
      }
      if (Map::roomExists(eastRoom, 'n') && eastRoom->getNorth()->hasKraken()) {
        return true;
      }
      if (Map::roomExists(eastRoom, 's') && eastRoom->getSouth()->hasKraken()) {
        return true;
      }
      return false;
    }
    case 's': {
      Room *southRoom = player.getRoom()->getSouth();
      if (southRoom->hasKraken()) {
        return true;
      }
      if (Map::roomExists(southRoom, 'e') &&
          southRoom->getEast()->hasKraken()) {
        return true;
      }
      if (Map::roomExists(southRoom, 'w') &&
          southRoom->getWest()->hasKraken()) {
        return true;
      }
      return false;
    }
    case 'w': {
      Room *westRoom = player.getRoom()->getWest();
      if (westRoom->hasKraken()) {
        return true;
      }
      if (Map::roomExists(westRoom, 'n') && westRoom->getNorth()->hasKraken()) {
        return true;
      }
      if (Map::roomExists(westRoom, 's') && westRoom->getSouth()->hasKraken()) {
        return true;
      }
      return false;
    }
    default:
      throw std::invalid_argument("Invalid direction");
    }
  }
  return false;
}

void Harpoon::pickup(Player &player) {
  std::cout << "You find a harpoon." << std::endl;
  player.addHarpoon();
}

bool Harpoon::use(Player &player, char direction) {
  // check if room exists before checking if Kraken is in the room
  if (Map::roomExists(player.getRoom(), direction)) {
    // check if Kraken is in the room
    switch (direction) {
    case 'n':
      return player.getRoom()->getNorth()->hasKraken();
    case 'e':
      return player.getRoom()->getEast()->hasKraken();
    case 's':
      return player.getRoom()->getSouth()->hasKraken();
    case 'w':
      return player.getRoom()->getWest()->hasKraken();
    default:
      throw std::invalid_argument("Invalid direction");
    }
  } else {
    return false;
  }
}
