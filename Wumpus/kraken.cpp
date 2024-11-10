//
// Created by deald on 10/27/2024.
//
#include "map.h"
#include "kraken.h"
Kraken::Kraken() {
    symbol = '#';
}


void Kraken::trigger(Map map, Player player) const {
    map.set_game_over(true);
    map.set_win(false);
}

