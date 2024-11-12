/*
 * innards.cpp
 * @brief The implementation of the Innards class
 */

#include "innards.h"

#include <iostream>
#include <ostream>

char Innards::getSymbol() const { return symbol; }

void Innards::display() const { std::cout << symbol; }

void Innards::trigger(Map &map, Player &player) {}
