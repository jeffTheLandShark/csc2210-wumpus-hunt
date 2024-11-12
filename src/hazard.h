/*
 * hazard.h
 *
 * @brief Hazards are special innards that can move the player to a different
 * room. They are triggered when the player enters the room.
 */

#ifndef HAZARD_H
#define HAZARD_H
#include "innards.h"


/**
 * Base class for hazards.
 *
 */
class Hazard : public Innards {
public:
  /**
   * Constructor for a hazard.
   *
   * @param symbol The symbol to represent the hazard.
   * @param airLoss The amount of air the player loses when they enter the room.
   */
  Hazard(char symbol, int airLoss) : Innards(symbol) {
    this->airLoss = airLoss;
  }

protected:
  /**
   * The amount of air the player loses when they enter the room.
   */
  int airLoss;
};

/**
 * A riptide hazard.
 *
 * When the player enters the room, they are moved to a random edge room.
 */
class Riptide : public Hazard {
public:
  Riptide() : Hazard('!', 5) {}
  /**
   * Activated when the player enters the room - moves the player to a random
   * edge room.
   * @param map the map object
   * @param player the player object
   */
  void trigger(Map &map, Player &player) override;
};

/**
 * A whirlpool hazard.
 *
 * When the player enters the room, they are moved to a random room.
 */
class Whirlpool : public Hazard {
public:
  Whirlpool() : Hazard('@', 10) {}
  /**
   * Activated when the player enters the room - moves the player to a random
   * room
   * @param map the map object
   * @param player the player object
   */
  void trigger(Map &map, Player &player) override;
};

#endif // HAZARD_H
