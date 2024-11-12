//
// Created by deald on 10/30/2024.
//
#include "room.h"
#include "player.h"
#include "map.h"
#include <iostream>
using namespace std;

Player::Player() {
  air = STARTING_AIR;
  numHarpoons = STARTING_WEAPONS;
  numNets = STARTING_WEAPONS;
  location = nullptr;
}

int Player::getAir() const {
  return air;
}

int Player::getNets() const {
  return numNets;
}

int Player::getHarpoons() const {
  return numHarpoons;
}

void Player::addAir(int tankAir) {
  air += tankAir;
}

void Player::addNet() {
  numNets++;
}

void Player::addHarpoon() {
  numHarpoons++;
}

void Player::setRoom(Room *room) {
  this->location = room;
  air--;
}

Room *Player::getRoom() const {
  return location;
}

void Player::playerMove(char dir) {
  //tolower
  if (location != nullptr) {
    switch (dir) {
      case 'n':
        if (Map::roomExists(location, dir)) {
          setRoom(location->getNorth());
        } else {
          cout << "You can't move north" << endl;
        }
        break;
      case 'e':
        if (Map::roomExists(location, dir)) {
          setRoom(location->getEast());
        } else {
          cout << "You can't move east" << endl;
        }
        break;
      case 's':
        if (Map::roomExists(location, dir)) {
          setRoom(location->getSouth());
        } else {
          cout << "You can't move south" << endl;
        }
        break;
      case 'w':
        if (Map::roomExists(location, dir)) {
          setRoom(location->getWest());
        } else {
          cout << "You can't move west" << endl;
        }
        break;
      default:
        cout << "Unknown direction" << endl;
    }
  }
}

void Player::useItem(Map &map, char letter, char direction) {
  bool hit;
  if (Map::roomExists(location, direction)) {
    switch (letter) {
      case 'h':
        if (numHarpoons > 0) {
          Harpoon harpoon;
          hit = harpoon.use(*this, direction);
          map.set_game_over(hit);
          map.set_win(hit);
          if (hit) {
            cout << "You shot the kraken" << endl;
          } else {
            cout << "You missed" << endl;
          }
          numHarpoons--;
        } else {
          cout << "Not enough harpoons" << endl;
        }
        break;
      case 't':
        if (numNets > 0) {
          Net net;
          hit = net.use(*this, direction);
          if (hit == true) {
            cout << "The kraken was in the " << direction << " direction" << endl;
          } else {
            cout << "You missed" << endl;
          }
          numNets--;
        } else {
          cout << "Not enough nets" << endl;
        }
        break;
      default:
        cout << "Unknown weapon" << endl;
    }
  } else {
    cout << "You can't shoot in that direction" << endl;
  }
}

void Player::printNear() const {
  //ennsures symbols are defined, and are irrelevant if they are not changed
  char nSymbol = '0';
  char sSymbol = '0';
  char eSymbol = '0';
  char wSymbol = '0';
  //changes symbols if a room in that direction exist, prevents symbol setting from null room
  if (getRoom()->getNorth() != nullptr) {
    nSymbol = getRoom()->getNorth()->getInnard()->getSymbol();
  }
  if (getRoom()->getEast() != nullptr) {
    eSymbol = getRoom()->getEast()->getInnard()->getSymbol();
  }
  if (getRoom()->getSouth() != nullptr) {
    sSymbol = getRoom()->getSouth()->getInnard()->getSymbol();
  }
  if (getRoom()->getWest() != nullptr) {
    wSymbol = getRoom()->getWest()->getInnard()->getSymbol();
  }

  bool empty = true;
  if (nSymbol == '#' || sSymbol == '#' || eSymbol == '#' || wSymbol == '#') {
    cout << "You feel a chill and a sense of dread." << endl;
    empty = false;
  }
  if (nSymbol == '@' || sSymbol == '@' || eSymbol == '@' || wSymbol == '@') {
    cout << "You feel water swirling nearby." << endl;
    empty = false;
  }
  if (nSymbol == '!' || sSymbol == '!' || eSymbol == '!' || wSymbol == '!') {
    cout << "You feel water pulling past you." << endl;
    empty = false;
  }
  if(empty) {
    cout << "It is dark and wet." << endl;
  }
}