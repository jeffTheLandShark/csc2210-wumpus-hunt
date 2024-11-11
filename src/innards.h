//
// Created by dicksonn on 10/29/2024.
//

#ifndef INNARDS_H
#define INNARDS_H


class Map;
class Player;

class Innards {
public:
  Innards() : Innards('.') {}
  Innards(char symbol) : symbol(symbol) {}
  void display() const;
  char getSymbol() const;
  virtual void trigger(Map &map, Player &player);

private:
  char symbol;
};

#endif //INNARDS_H