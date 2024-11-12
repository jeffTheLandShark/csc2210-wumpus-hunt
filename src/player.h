/*
 * player.h
 * @brief: The Player class is responsible for managing the player's inventory
 * and location in the game.
 */

#ifndef PLAYER_H
#define PLAYER_H

class Map;
class Room;
// starting values for the player
constexpr int STARTING_AIR = 50;
constexpr int STARTING_WEAPONS = 1;

/**
 * @brief The Player class is responsible for managing the player's inventory
 */
class Player {
public:
  /**
   * @brief Construct a new Player object
   * @note The constructor initializes the player's air, number of nets, number
   * of harpoons, and location.
   */
  Player();
  int getAir() const;
  int getNets() const;
  int getHarpoons() const;
  void addAir(int tankAir);
  void addNet();
  void addHarpoon();
  void setRoom(Room *room);
  Room *getRoom() const;
  /**
   * @brief Move the player in a direction
   */
  void playerMove(char dir);
  /**
   * @brief Use an item in a direction
   * @param map: The map object
   * @param letter: The item to use
   * @param direction: The direction to use the item
   */
  void useItem(Map &map, char letter, char direction);
  /**
   * @brief Print the hints for the rooms near the player
   */
  void printNear() const;

private:
  int air;
  int numNets;
  int numHarpoons;
  Room *location;
};

#endif // PLAYER_H
