//
// Created by deald on 10/27/2024.
//

//Kraken stuff
#ifndef KRACKEN_H
#define KRACKEN_H
#include "innards.h"


class Kraken : public Innards {
public:
  Kraken() : Innards('#') {}
  void trigger(Map &map, Player &player) override;
};


#endif //KRACKEN_H
