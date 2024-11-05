//
// Created by deald on 10/30/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Room.h"

constexpr int STARTING_AIR = 50;
constexpr int STARTING_WEAPONS = 1;


class player {
public:
  player();
  ~player();

  int getAir() const;
  int getNets() const;
  int getHarpoons() const;
  void addAir(int tankAir);
  void addNet();
  void addHarpoon();
  void setRoom(room* room);
  room* getRoom() const;

private:
  int air = STARTING_AIR;
  int numNets = STARTING_WEAPONS;
  int numHarpoons = STARTING_WEAPONS;
  room* location;

};


#endif //PLAYER_H
