#include <iostream>
#include <windows.h>
#include <algorithm>
#include "map.h"
using namespace std;
void help();
void setup();
string toLowerCase(string str);
void printOptions(const Player *player);
int main() {
    setup();
    auto *player = new Player();
    Map* map = new Map(player);

    string input;
    string weaponDir;
    while(input != "q" && !map->is_over()) {
        player->printNear();
        printOptions(player);
        cin >> input;
        input = toLowerCase(input);

        if(input == "h") {
            help();
        } else if(input == "m") {
            map->display(player->getRoom());
        } else if(input == "r") {
            while(weaponDir != "n" && weaponDir != "s" && weaponDir != "e" && weaponDir != "w") {
                cout << "use harpoon in which direction? (n/s/e/w)";
                cin >> weaponDir;
                weaponDir = toLowerCase(weaponDir);
            }
            player->useItem(*map,'h', weaponDir.at(0));
            weaponDir = "";
        } else if(input == "t") {
            while(weaponDir != "n" && weaponDir != "s" && weaponDir != "e" && weaponDir != "w") {
                cout << "use net in which direction? (n/s/e/w)";
                cin >> weaponDir;
                weaponDir = toLowerCase(weaponDir);
            }
            player->useItem(*map, 't', weaponDir.at(0));
            weaponDir = "";
        } else if(input == "n" || input == "s" || input == "e" || input == "w") {
            player->playerMove(input.at(0));
            player->getRoom()->getInnard()->trigger(*map , *player);
        }
    }
    if(map->is_win()) {
        cout << "You win!";
    } else {
        cout << "You lose!";
    }
    delete map;
    delete player;
    return 0;
}

void help() {
    cout << "Welcome to hunt the Kraken. You are a deep sea scuba diver seeking to kill the Kraken before you run out of oxygen. The sea floor is divided into 30 spaces in a 5 high 6 wide rectangle. Each space is connected to 4 others." << endl << endl;
    cout << "Hazards:" << endl;
    cout << "Whirlpool - One space has a whirlpool. If you go there, you will be whisked away to a random space and will lose 5 oxygen." << endl;
    cout << "Riptide - Two spaces have riptides. These will drown you and you will lose." << endl << endl;
    cout << "Kraken:" << endl;
    cout << "The Kraken is not affected by hazards. The Kraken is usually asleep. If you shoot a Harpoon and miss, he might wake up and move to an adjacent space. If you attempt to move into the Kraken's space, it eats you and you lose." << endl << endl;
    cout << "You:" << endl;
    cout << "Each turn you may move or use a weapon."  << endl;
    cout << "Moving: You can move one space North, South, East, or West if there is a room in that direction." << endl;
    cout << "Oxygen: Each move consumes 1 Oxygen. If you run out of Oxygen you lose. There is one Oxygen tank that you can find." << endl;
    cout << "Using Weapons: You can use the Harpoon to attack an adjacent space (you start with 2 harpoons and can find 2 more)." << endl;
    cout << "If you hit the Kraken with a Harpoon, you win." << endl;
    cout << "If you find the net, you can throw it to see if the Kraken is hiding in any of the nearest 3 spaces in the direction you choose. The net does not kill the Kraken." << endl;
    cout << "You will be given hints indicating when a hazard or the Kraken is nearby." << endl << endl;
}

void setup() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,
      FOREGROUND_BLUE);
}

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void printOptions(const Player *player) {
    cout << "\nAction: (N)orth, (S)outh, (E)ast, (W)est, (M)ap, (H)elp";
    if(player->getHarpoons() > 0) {
        cout << ", shoot ha(R)poon";
    }
    if(player->getNets() > 0) {
        cout << ", use ne(T)";
    }
    cout << ", Q)uit: ";
}
