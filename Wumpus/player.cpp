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
bool Player::playerMove(char dir) {
    //tolower
    if(location!=nullptr) {
        switch (dir) {
            case 'n':
                if(location->getNorth() != nullptr) {
                    setRoom(location->getNorth());
                }
                return location->getNorth()!=nullptr;
            case 'e':
                if(location->getEast()!=nullptr) {
                    setRoom(location->getEast());
                }
            return location->getEast()!=nullptr;
            case 's':
                if(location->getSouth()!=nullptr) {
                    setRoom(location->getSouth());
                }
            return location->getSouth()!=nullptr;
            case 'w':
                if(location->getWest()!=nullptr) {
                    setRoom(location->getWest());
                }
            return location->getWest()!=nullptr;
            default:
                return false;
        }
    }
    return false;
}

void Player::useItem(char letter, char direction) {
    switch (letter) {
        case 'h':
            if(numHarpoons>0) {
                Harpoon harpoon;
                harpoon.use(*this, direction);
            }
            break;
        case 'n':
            if(numNets>0) {
                Net net;
                net.use(*this, direction);
            }
            break;
    }
}
void Player::printNear() const{
    const char nSymbol = getRoom()->getNorth()->getInnard()->getSymbol();
    const char sSymbol = getRoom()->getSouth()->getInnard()->getSymbol();
    const char eSymbol = getRoom()->getEast()->getInnard()->getSymbol();
    const char wSymbol = getRoom()->getWest()->getInnard()->getSymbol();
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