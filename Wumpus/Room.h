//
// Created by deald on 10/27/2024.
//

#ifndef ROOM_H
#define ROOM_H
#include "Hazard.h"
#include "Item.h"


class Room {
    public:
private:
    Room *north;
    Room *east;
    Room *south;
    Room *west;
    //only has item or hazard
    Item *item;
    Hazard *hazard;
};



#endif //ROOM_H
