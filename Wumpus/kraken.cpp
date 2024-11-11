//
// Created by deald on 10/27/2024.
//
#include "map.h"
#include "kraken.h"

#include <iostream>

void Kraken::trigger(Map &map, Player &player) {
  std::cout << "You have stepped on the mighty kraken" << std::endl;
  map.set_game_over(true);
  map.set_win(false);
}
