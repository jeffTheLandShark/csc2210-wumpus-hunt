/*
 *
 *
 */
#include "room.h"
#include "items.h"
#include "player.h"

#include <iostream>

#include "map.h"

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
  bool hit = false;
  switch (direction) {
    case 'n': {
      Room *northRoom = player.getRoom()->getNorth();
      if(northRoom == nullptr) {
        return false;
      }
      if(northRoom->hasKraken()) {
        hit=true;
      }
      if(northRoom->getEast() != nullptr) {
        if(!hit) {
          if(northRoom->getEast()->hasKraken()) {
            hit=true;
          }
        }
      }
      if(northRoom->getWest() != nullptr) {
        if(!hit) {
          if(northRoom->getWest()->hasKraken()) {
            hit=true;
          }
        }
      }
      return hit;
    }
    case 'e': {
      Room *eastRoom = player.getRoom()->getEast();
      //exits method because it cannot be in that direction
      if(eastRoom == nullptr) {
        return false;
      }
      if(eastRoom->hasKraken()) {
        hit = true;
      }

      if(eastRoom->getNorth() != nullptr) {
        if(!hit) {
          if(eastRoom->getNorth()->hasKraken()) {
            hit = true;
          }
        }
      }
      if(eastRoom->getSouth() != nullptr) {
        if(!hit) {
          if(eastRoom->hasKraken()) {
            hit = true;
          }
        }
      }
      return hit;
    }
    case 's': {
      Room *southRoom = player.getRoom()->getSouth();
      if(southRoom == nullptr) {
        return false;
      }
      if(southRoom->hasKraken()) {
        hit = true;
      }
      if(southRoom->getNorth() != nullptr) {
        if(!hit) {
          if(southRoom->getNorth()->hasKraken()) {
            hit = true;
          }
        }
      }
      if(southRoom->getSouth() != nullptr) {
        if(!hit) {
          if(southRoom->getSouth()->hasKraken()) {
            hit = true;
          }
        }
      }

      return hit;
    }
    case 'w': {
      Room *westRoom = player.getRoom()->getWest();
      if(westRoom == nullptr) {
        return false;
      }
      if(westRoom->hasKraken()) {
        hit = true;
      }
      if(westRoom->getNorth() != nullptr) {
        if(!hit) {
          if(westRoom->getNorth()->hasKraken()) {
            hit = true;
          }
        }
      }
      if(westRoom->getSouth() != nullptr) {
        if(!hit) {
          if(westRoom->getSouth()->hasKraken()) {
            hit=true;
          }
        }
      }
      return hit;
    }
    default:
      throw std::invalid_argument("Invalid direction");
  }
}

void Harpoon::pickup(Player &player) {
  std::cout << "You find a harpoon." << std::endl;
  player.addHarpoon();
}

bool Harpoon::use(Player &player, char direction) {
  switch (direction) {
    case 'n':
      if (player.getRoom() != nullptr && player.getRoom()->getNorth() != nullptr) {
        return player.getRoom()->getNorth()->hasKraken();
      }
      return false;
    case 'e':
      if (player.getRoom() != nullptr && player.getRoom()->getEast() != nullptr) {
        return player.getRoom()->getEast()->hasKraken();
      }
      return false;
    case 's':
      if (player.getRoom() != nullptr && player.getRoom()->getSouth() != nullptr) {
        return player.getRoom()->getSouth()->hasKraken();
      }
      return false;
    case 'w':
      if (player.getRoom() != nullptr && player.getRoom()->getWest() != nullptr) {
        return player.getRoom()->getWest()->hasKraken();
      }
      return false;
    default:
      throw std::invalid_argument("Invalid direction");
  }
}
