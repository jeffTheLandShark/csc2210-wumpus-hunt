//
// Created by deald on 10/30/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
class Room;
#include "items.h"

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
  void setRoom(Room* room);
  Room* getRoom() const;
  void playerMove(char dir);
  void useItem(Map& map, char letter, char direction);

  void printNear() const;

private:
  int air;
  int numNets;
  int numHarpoons;
  Room* location;

};


#endif //PLAYER_H
