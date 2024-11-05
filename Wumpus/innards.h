//
// Created by dicksonn on 10/29/2024.
//

#ifndef INNARDS_H
#define INNARDS_H

class Innards {
public:
  Innards(char symbol);
  char getSymbol() const;
  void display() const;
private:
char symbol;
};

#endif //INNARDS_H