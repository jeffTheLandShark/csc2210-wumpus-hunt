/*
 * map.h
 * @brief: The Map class is responsible for creating the game map and displaying
 * it. It also contains the logic for the game to end and for the player to win.
 */

#ifndef MAP_H
#define MAP_H

class Room;
class Player;
/**
 * @brief The Map class is responsible for creating the game map and displaying
 * it. It also contains the logic for the game to end and for the player to win.
 * @note: The Map class generates a 5x6 grid of rooms and randomly places
 * hazards and items in them.
 */
class Map {
public:
  /**
   * @brief Construct a new Map object
   * @param player: The player object
   * @note The constructor creates a 5x6 grid of rooms and randomly places
   * hazards and items in them. It also sets the player's room to a random room
   * that does not contain a hazard.
   */
  Map(Player *player);
  /**
   * @brief Display the map
   * @param playerRoom: The room the player is currently in
   * @note The function displays the map with the player's position marked by a
   * '+'
   */
  void display(const Room *playerRoom) const;
  /**
   * @brief Get a random room
   * @return Room*: A random room that does not contain a hazard
   * @note The function generates a random room that does not contain a hazard
   */
  Room *get_random_room() const;
  /**
   * @brief Check if the game is over
   * @return bool: True if the game is over, false otherwise
   */
  bool is_over() const;
  /**
   * @brief Check if the player has won
   * @return bool: True if the player has won, false otherwise
   */
  bool is_win() const;
  /**
   * @brief Set the game over status
   * @param game_over: The game over status
   */
  void set_game_over(bool);
  /**
   * @brief Set the win status
   * @param win: The win status
   */
  void set_win(bool);
  /**
   * @brief Check if a room exists in a given direction
   * @param room: The room to check
   * @param dir: The direction to check
   * @return bool: True if a room exists in the given direction, false otherwise
   */
  static bool roomExists(Room *room, char dir);
  /**
   * @brief Destroy the Map object
   */
  ~Map();

private:
  /**
   * @brief The first room in the map
   */
  Room *first_room;
  /**
   * @brief The rooms in the map
   */
  Room *rooms[30]{};
  /**
   * @brief The game over status
   */
  bool game_over;
  /**
   * @brief The win status
   */
  bool win;
};

#endif // MAP_H
