//
// Created by deald on 10/27/2024.
//

#include "innards.h"

#include <iostream>
#include <ostream>

char Innards::getSymbol() const {
  return symbol;
}

void Innards::display() const {
  std::cout << symbol;
}

void Innards::trigger() const {
  std::cout << "It is dark and wet";
}
