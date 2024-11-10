//
// Created by deald on 10/27/2024.
//

//Kraken stuff
#ifndef KRACKEN_H
#define KRACKEN_H
#include "innards.h"


class Kraken : public Innards {
public:
    Kraken();
    Kraken(char symbol) : Innards(symbol) {};

    ~Kraken();
    void trigger(Map& map, Player& player) const override;
private:
    char symbol;
};



#endif //KRACKEN_H
