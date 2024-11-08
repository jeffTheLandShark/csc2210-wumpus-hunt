//
// Created by deald on 10/30/2024.
//

#include "player.h"
Player::Player() {

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
    switch (dir) {
        case 'n':
            //todo north != nullptr
            break;
        case 'e':
            return false;
        case 's':
            return true;
        case 'w':
            return true;
    }
}
