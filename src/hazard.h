//
// Created by deald on 10/27/2024.
//

#ifndef HAZARD_H
#define HAZARD_H
#include "innards.h"

class Hazard : public Innards {
public:
  Hazard(char symbol) : Innards(symbol) {}
  Hazard(char symbol, int airLoss) : Innards(symbol) { this->airLoss = airLoss; }
protected:
  int airLoss;
};

class Riptide : public Hazard {
public:
  Riptide() : Hazard('!', 5) {}
  void trigger(Map &map, Player &player) override;
};

class Whirlpool : public Hazard {
public:
  Whirlpool() : Hazard('@', 10) {}
  void trigger(Map &map, Player &player) override;
};


#endif //HAZARD_H
