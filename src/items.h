/*
 * items.h
 *
 * @brief: Items are objects that the player can pick up and use.
 * @note: Items are a subclass of Innards, and are used to trigger
 *         events in the game.
 */

#ifndef ITEM_H
#define ITEM_H

#include "innards.h"

/**
  * @brief: Items are objects that the player can pick up and use.
 */
class Items : public Innards {
public:
  /**
   * @brief: Constructor for Items.
   * @param: symbol, the symbol that represents the item.
   */
  Items(char symbol) : Innards(symbol) {}
  /**
   * @brief: Destructor for Items.
   */
  ~Items() = default;

  /**
   * @brief: Pickup the item.
   * @param: player, the player that picks up the item.
   */
  virtual void pickup(Player &player) = 0;

  /**
   * @brief: Trigger the item. Calls pickup and sets the room to an empty room.
   * @param: map, the map that the player is on.
   * @param: player, the player that triggers the item.
   */
  void trigger(Map &map, Player &player) override;
};

/**
 * @brief: AirTank is an item that gives the player more air.
 */
class AirTank : public Items {
public:
  /**
   * @brief: Constructor for AirTank.
   * @note: Default constructor gives 5 air.
   */
  AirTank() : AirTank(5) {}
  /**
   * @brief: Constructor for AirTank.
   * @param: air, the amount of air that the AirTank gives.
   */
  AirTank(int air) : Items('?'), air(air) {}
  void pickup(Player &player) override;

private:
  /**
   * @brief: The amount of air that the AirTank gives.
   */
  int air;
};

/**
 * @brief: Weapon is an item that the player can use to attack or sense the
 * Kraken.
 * @note: Weapons are added to the player's inventory.
 */
class Weapon : public Items {
public:
  /**
   * @brief: Constructor for Weapon.
   */
  Weapon() : Items('>') {}
  ~Weapon() = default;
  /**
   * @brief: Use the weapon. This removes the weapon from the player's
   * inventory.
   */
  virtual bool use(Player &player, char direction) = 0;
};

/**
 * @brief: Net is a weapon that the player can sense the Kraken with.
 * @note: The Net sense the Kraken in the 3 rooms in the direction that the
 *        player uses the Net.
 */
class Net : public Weapon {
public:
  /**
   * @brief: Add 1 Net to the player's inventory.
   */
  void pickup(Player &player) override;
  /**
   * @brief: Use the Net. This senses the Kraken in the 3 rooms in the
   *        direction that the player uses the Net.
   * @param: player, the player that uses the Net.
   * @param: direction, the direction that the player uses the Net.
   * @return: true if the Kraken is in one of the 3 rooms, false otherwise.
   * @note: The Net can only be used in the cardinal directions, similar to
   *        the player's movement.
   */
  bool use(Player &player, char direction) override;
};

class Harpoon : public Weapon {
public:
  /**
   * @brief: Add 1 Harpoon to the player's inventory.
   */
  void pickup(Player &player) override;
  /**
   * @brief: Use the Harpoon. This attacks the Kraken in the room in the
   *        direction that the player uses the Harpoon.
   * @param: player, the player that uses the Harpoon.
   * @param: direction, the direction that the player uses the Harpoon.
   * @return: true if the Kraken is in one of the 3 rooms, false otherwise.
   * @note: The Harpoon can only be used in the cardinal directions, similar to
   *        the player's movement.
   */
  bool use(Player &player, char direction) override;
};

#endif // ITEM_H