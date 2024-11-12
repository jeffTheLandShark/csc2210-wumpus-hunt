/*
 * innards.h
 *
 * @brief Innards are the contents of a room. They can be interacted with by the
 * player.
 */

#ifndef INNARDS_H
#define INNARDS_H

class Player;
class Map;
/**
 * Base class for innards.
 *
 */
class Innards {
public:
 virtual ~Innards() = default;

 Innards() : Innards('.') {}
  Innards(char symbol) : symbol(symbol) {}
  /**
   * @brief Displays the innards
   */
  void display() const;
  /**
   * @brief Gets the symbol of the innards
   */
  char getSymbol() const;
  /**
   * @brief Triggers the innards
   * This method is empty because the base class does not have any special
   * behavior
   */
  virtual void trigger(Map &map, Player &player);

private:
  char symbol;
};

#endif // INNARDS_H