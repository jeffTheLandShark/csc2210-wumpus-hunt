/*
 *
 *
 */

#include "items.h"
#include "player.h"

#include <iostream>

void AirTank::pickup(Player player) {
  player.addAir(air);
  std::cout << "AirTank::pickup" << std::endl << "Current Air: " << player.getAir() << std::endl;
}

void Net::pickup(Player player) {
  player.addNet();
}

bool Net::use(Player player, char direction) {
  //todo check for nullptrs
  /*
  switch (direction) {
    case 'n': {
      Room *northRoom = player.getRoom()->getNorth();

      return northRoom->hasKraken() || northRoom->getEast()->hasKraken() || northRoom->getWest()->hasKraken();
    }
    case 'e': {
      Room *eastRoom = player.getRoom()->getEast();
      return eastRoom->hasKraken() || eastRoom->getNorth()->hasKraken() || eastRoom->getSouth()->hasKraken();
    }
    case 's': {
      Room *southRoom = player.getRoom()->getSouth();
      return southRoom->hasKraken() || southRoom->getEast()->hasKraken() || southRoom->getWest()->hasKraken();
    }
    case 'w': {
      Room *westRoom = player.getRoom()->getWest();
      return westRoom->hasKraken() || westRoom->getNorth()->hasKraken() || westRoom->getSouth()->hasKraken();
    }
    default:
      throw std::invalid_argument("Invalid direction");
  }
  */
  return false;
}

void Harpoon::pickup(Player player) {
  player.addHarpoon();
}

bool Harpoon::use(Player player, char direction) {
  switch (direction) {
    case 'n':
      if(player.getRoom() != nullptr && player.getRoom()->getNorth() != nullptr) {
        return player.getRoom()->getNorth()->hasKraken();
      }
    return false;
    case 'e':
      if(player.getRoom() != nullptr && player.getRoom()->getEast() != nullptr) {
        return player.getRoom()->getNorth()->hasKraken();
      }
    return false;
    case 's':
      if(player.getRoom() != nullptr && player.getRoom()->getSouth() != nullptr) {
        return player.getRoom()->getNorth()->hasKraken();
      }
    return false;
    case 'w':
      if(player.getRoom() != nullptr && player.getRoom()->getWest() != nullptr) {
        return player.getRoom()->getNorth()->hasKraken();
      }
    return false;
    default:
      throw std::invalid_argument("Invalid direction");
  }
}
