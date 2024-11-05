//
// Created by deald on 10/30/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Room.h"

constexpr int STARTING_AIR = 50;
constexpr int STARTING_WEAPONS = 1;


class Player {
public:
  Player();
  ~Player();

  int getAir() const;
  int getNets() const;
  int getHarpoons() const;
  void addAir(int tankAir);
  void addNet();
  void addHarpoon();
  Room *getRoom() const;

private:
  int air = STARTING_AIR;
  int numNets = STARTING_WEAPONS;
  int numHarpoons = STARTING_WEAPONS;
  Room location;

};


#endif //PLAYER_H
