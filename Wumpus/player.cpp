//
// Created by deald on 10/30/2024.
//
#include "room.h"
#include "player.h"

#include <iostream>
using namespace std;

Player::Player() {
    air = STARTING_AIR;
    numHarpoons = STARTING_WEAPONS;
    numNets = STARTING_WEAPONS;
    location = nullptr;
}
Player::~Player() {

}

int Player::getAir() const {
    return air;
}
int Player::getNets() const {
    return numNets;
}
int Player::getHarpoons() const {
    return numHarpoons;
}
void Player::addAir(int tankAir) {
    air += tankAir;
}
void Player::addNet() {
    numNets++;
}
void Player::addHarpoon() {
    numHarpoons++;
}
void Player::setRoom(Room* room) {
    this->location=room;
}
Room* Player::getRoom() const{
    return location;
}
void Player::playerMove(char dir) {
    //tolower
    if(location!=nullptr) {
        switch (dir) {
            case 'n':
                if(location->getNorth() != nullptr) {
                    setRoom(location->getNorth());
                } else {
                    cout << "You can't move north" << endl;
                }
                break;
            case 'e':
                if(location->getEast()!=nullptr) {
                    setRoom(location->getEast());
                } else {
                    cout << "You can't move east" << endl;
                }
            break;
            case 's':
                if(location->getSouth()!=nullptr) {
                    setRoom(location->getSouth());
                } else {
                    cout << "You can't move south" << endl;
                }
                break;
            case 'w':
                if(location->getWest()!=nullptr) {
                    setRoom(location->getWest());
                } else {
                    cout << "You can't move west" << endl;
                }
                break;
            default:
                cout << "Unknown direction" << endl;
        }
    }
}

void Player::useItem(char letter, char direction) {
    switch (letter) {
        case 'h':
            if(numHarpoons>0) {
                Harpoon harpoon;
                harpoon.use(*this, direction);
            }
            break;
        case 't':
            if(numNets>0) {
                Net net;
                net.use(*this, direction);
            }
            break;
    }
}
void Player::printNear() const {
    char nSymbol ='0';
    char sSymbol ='0';
    char eSymbol ='0';
    char wSymbol ='0';
    if(getRoom()->getNorth()!=nullptr) {
        nSymbol = getRoom()->getNorth()->getInnard()->getSymbol();
    }
    if(getRoom()->getEast()!=nullptr) {
        eSymbol = getRoom()->getEast()->getInnard()->getSymbol();
    }
    if(getRoom()->getSouth()!=nullptr) {
        sSymbol = getRoom()->getSouth()->getInnard()->getSymbol();
    }
    if(getRoom()->getWest()!=nullptr) {
        wSymbol = getRoom()->getWest()->getInnard()->getSymbol();
    }
    bool empty = true;
    if(nSymbol == '#' || sSymbol == '#' || eSymbol == '#' || wSymbol == '#') {
        cout << "Kraken is nearby." << endl;
        empty = false;
    }
    if(nSymbol == '@' || sSymbol == '@' || eSymbol == '@' || wSymbol == '@') {
        cout << "Whirlpool is nearby." << endl;
        empty = false;
    }
    if(nSymbol == '!' || sSymbol == '!' || eSymbol == '!' || wSymbol == '!') {
        cout << "Riptide is nearby." << endl;
        empty = false;
    }
    if(empty) {
        cout << "It is dark." << endl;
    }
}