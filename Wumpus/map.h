//
// Created by deald on 10/27/2024.
//
// Contains rooms
#ifndef MAP_H
#define MAP_H

#include "room.h"

class Map {
public:
  Map(Player *player);
  void display(const Room *playerRoom) const;
  Room *get_random_room() const;
  bool is_over()  const;
  bool is_win() const;
  void set_game_over(bool);
  void set_win(bool);
private:
  Room *first_room;
  Room *rooms[30]{};
  bool game_over;
  bool win;
};

#endif //MAP_H
