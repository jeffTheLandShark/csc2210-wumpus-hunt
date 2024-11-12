/*
 * room.h
 * @brief: The Room class is responsible for managing the rooms in the game.
 */

#ifndef ROOM_H
#define ROOM_H

class Innards;
/**
 * @brief The Room class is responsible for managing the rooms in the game.
 * @note The Room class contains pointers to the rooms in each direction, as
 * well as a pointer to the innards of the room.
 */
class Room {
public:
  /**
   * @brief Construct a new Room object
   * @note The constructor initializes the pointers to the rooms in each
   * direction and the innards of the room.
   */
  Room();
  ~Room();
  void setNorth(Room *room);
  void setSouth(Room *room);
  void setEast(Room *room);
  void setWest(Room *room);

  Room *getNorth() const;
  Room *getSouth() const;
  Room *getEast() const;
  Room *getWest() const;

  /**
   * @brief Check if the room contains a kraken
   * @return bool: True if the room contains a kraken, false otherwise
   */
  bool hasKraken() const;
  void setInnard(Innards *innard);
  Innards *getInnard() const;
  /**
   * @brief Display the innards of the room
   */
  void display() const;
  /**
   * @brief Check if the room is an edge room
   * @return bool: True if the room is an edge room, false otherwise
   */
  bool isEdge() const;

private:
  Room *north;
  Room *east;
  Room *south;
  Room *west;

  /**
   * @brief A pointer to the innards of the room
   */
  Innards *innard;
};

#endif // ROOM_H