/*
 * kraken.h
 * @brief: Kraken is an item that triggers automatically when the player
 * steps on it. It will automatically attack the player and end the game.
 */

#ifndef KRACKEN_H
#define KRACKEN_H

#include "innards.h"

/**
 * @brief: Kraken is an item that triggers automatically when the player
 * steps on it. It will automatically attack the player and end the game.
 */
class Kraken : public Innards {
public:
  /**
   * @brief: Constructor for Kraken.
   */
  Kraken() : Innards('#') {}
  /**
   * @brief: Triggered when the player steps on the Kraken. It will
   * show the Kraken and end the game.
   * @param map: The map object that the player is on.
   * @param player: The player object that stepped on the Kraken.
   */
  void trigger(Map &map, Player &player) override;
};

#endif // KRACKEN_H
