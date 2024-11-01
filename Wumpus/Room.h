//
// Created by deald on 10/27/2024.
//

#ifndef ROOM_H
#define ROOM_H
#include "Innards.h"


class Room {
    public:
    Room();
    void setNorth(Room *room);
    void setSouth(Room *room);
    void setEast(Room *room);
    void setWest(Room *room);
    Room getNorth() const;
    Room getSouth() const;
    Room getEast() const;
    Room getWest() const;

    void setInnard(Innards *innard);
    Innards* getInnard() const;
    void display() const;
private:
    Room *north;
    Room *east;
    Room *south;
    Room *west;

    Innards *innard;
};

#endif //ROOM_H
