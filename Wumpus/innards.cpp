//
// Created by deald on 10/27/2024.
//

#include "innards.h"

#include <iostream>
#include <ostream>

Innards::Innards(char symbol) {
  this->symbol = symbol;
}
char Innards::getSymbol() const {
  return symbol;
}
void Innards::display() const {
  std::cout << symbol;
}

