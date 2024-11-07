//
// Created by dicksonn on 10/29/2024.
//

#ifndef INNARDS_H
#define INNARDS_H

class Innards {
public:
  Innards() : Innards('.') {}
  Innards(char symbol) : symbol(symbol) {}
  void display() const;
  void trigger() const;

protected:
  char symbol;
};

#endif //INNARDS_H