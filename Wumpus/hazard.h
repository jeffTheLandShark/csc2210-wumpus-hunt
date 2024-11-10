//
// Created by deald on 10/27/2024.
//

#ifndef HAZARD_H
#define HAZARD_H
#include "innards.h"


class Hazard : public Innards{
public:
  Hazard(char symbol) : Innards(symbol){}
  ~Hazard();
  virtual void trigger(Map map, Player player) = 0;
};

class Riptide : public Hazard {
public:
  Riptide() : Hazard('!'){}
  void trigger(Map map, Player player) override;
};

class Whirlpool : public Hazard {
public:
  Whirlpool() : Hazard('@'){}
  void trigger(Map map, Player player) override;
};


#endif //HAZARD_H
