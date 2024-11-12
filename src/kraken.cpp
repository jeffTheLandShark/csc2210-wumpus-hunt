/*
* kraken.cpp
* @brief The implementation of the Kraken class
*/

#include "kraken.h"

#include <iostream>

#include "map.h"

void Kraken::trigger(Map &map, Player &player) {
std::cout <<       "                      ___"
  << std::endl <<  "                   .-'   `'."
  << std::endl <<  "                  /         \\"
  << std::endl <<  "                  |         ;"
  << std::endl <<  "                  |         |           ___.--,"
  << std::endl <<  "         _.._     |>) ~ (<) |    _.---'`__.-( (_."
  << std::endl <<  "  __.--'`_.. '.__.\\    '--. \\_.-' ,.--'`     `""`"
  << std::endl <<  " ( ,.--'`   ',__ /./;   ;, '.__.'`    __"
  << std::endl <<  " _`) )  .---.__.' / |   |\\   \\__..--""  \"\"\"--.,_"
  << std::endl <<  "`---' .'.''-._.-'`_./  /\\ '.  \\ _.-~~~````~~~-._`-.__.'"
  << std::endl <<  "      | |  .' _.-' |  |  \\  \\  '.               `~---`"
  << std::endl <<  R"(       \ \/ .'     \  \   '. '-._))"
  << std::endl <<  R"(        \/ /        \  \    `=.__`~-.)"
  << std::endl <<  "        / /\\         `) )    / / `"".`\\"
  << std::endl <<  "  , _.-'.'\\ \\        / /    ( (     / /"
  << std::endl <<  "   `--~`   ) )    .-'.'      '.'.  | ("
  << std::endl <<  "          (/`    ( (`          ) )  '-;"
  << std::endl;
  std::cout << "You have stepped on the mighty kraken" << std::endl;
  map.set_game_over(true);
  map.set_win(false);
}
