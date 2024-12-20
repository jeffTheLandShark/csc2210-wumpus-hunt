#include "map.h"

#include <algorithm>
#include <iostream>
#include <windows.h>

#include "innards.h"
#include "player.h"
#include "room.h"

using namespace std;

/**
 * Shows the help menu
 */
void help();

/**
 * Sets up the console
 */
void setup();

/**
 * Converts a string to lowercase
 * @param str the string to convert
 * @return the converted string
 */
string toLowerCase(string str);

/**
 * Prints the options for the player
 * @param player the player
 * @param map the map
 */
void printOptions(const Player *player, const Map *map);

int main() {
  setup();
  auto *player = new Player();
  const auto map = new Map(player);

  string input;
  string weaponDir;

  bool debug = false;
  cout << "Play in debug mode? (y/n): ";
  cin >> input;
  if (toLowerCase(input) == "y") {
    debug = true;
  }
  input = "";

  while (input != "q" && !map->is_over()) {
    if (debug) {
      map->display(player->getRoom());
    }
    player->printNear();
    printOptions(player, map);
    cin >> input;
    input = toLowerCase(input);

    if (input == "h") {
      help();
    } else if (input == "m") {
      map->display(player->getRoom());
    } else if (input == "r") {
      while (weaponDir != "n" && weaponDir != "s" && weaponDir != "e" &&
             weaponDir != "w") {
        cout << "use harpoon in which direction? (n/s/e/w): ";
        cin >> weaponDir;
        weaponDir = toLowerCase(weaponDir);
      }
      player->useItem(*map, 'h', weaponDir.at(0));
      weaponDir = "";
    } else if (input == "t") {
      while (weaponDir != "n" && weaponDir != "s" && weaponDir != "e" &&
             weaponDir != "w") {
        cout << "use net in which direction? (n/s/e/w): ";
        cin >> weaponDir;
        weaponDir = toLowerCase(weaponDir);
      }
      player->useItem(*map, 't', weaponDir.at(0));
      weaponDir = "";
    } else if (input == "n" || input == "s" || input == "e" || input == "w") {
      player->playerMove(input.at(0));
      player->getRoom()->getInnard()->trigger(*map, *player);
      int airRemaining = player->getAir();
      if (airRemaining > 0 && !map->is_over()) {
        cout << "You have " << airRemaining << " units of oxygen remaining"
             << endl;
      } else if (!map->is_over()) {
        cout << "You have run out of air." << endl;
        map->set_game_over(true);
        map->set_win(false);
      }
    }
  }

  if (map->is_win()) {
    cout << "You win!";
  } else {
    cout << "You lose!";
  }
  delete map;
  delete player;
  return 0;
}

void help() {
  // This is pure text output for the help menu, so the size of the method is
  // not a concern
  cout << "Welcome to hunt the Kraken. You are a deep sea scuba diver seeking "
          "to kill the Kraken before you run out of oxygen. The sea floor is "
          "divided into 30 spaces in a 5 high 6 wide rectangle. Each space is "
          "connected to 4 others."
       << endl
       << endl;
  cout << "Hazards:" << endl;
  cout << "Whirlpool - One space has a whirlpool. If you go there, you will be "
          "whisked away to a random space and will lose 11 oxygen."
       << endl;
  cout << "Riptide - Two spaces have riptides. If you go there, you will be "
          "whisked away to a random space on the edge of the map and will lose "
          "6 oxygen."
       << endl
       << endl;
  cout << "Kraken:" << endl;
  cout << "If you attempt to move into the Kraken's space, it eats you and you "
          "lose."
       << endl
       << endl;
  cout << "You:" << endl;
  cout << "Each turn you may move or use a weapon." << endl;
  cout << "Moving: You can move one space North, South, East, or West if there "
          "is a room in that direction."
       << endl;
  cout << "Oxygen: Each move consumes 1 Oxygen. If you run out of Oxygen you "
          "lose. There is one Oxygen tank that you can find. You start with 50 "
          "Oxygen"
       << endl;
  cout << "Using Weapons: You can use the Harpoon to attack an adjacent space "
          "(you start with 1 harpoon and can find 2 more)."
       << endl;
  cout << "If you hit the Kraken with a Harpoon, you win." << endl;
  cout << "If you find the net, you can throw it to see if the Kraken is "
          "hiding in any of the nearest 3 spaces in the direction you choose. "
          "The net does not kill the Kraken."
       << endl;
  cout << "You will be given hints indicating when a hazard or the Kraken is "
          "nearby."
       << endl
       << endl;
}

void setup() {
  // get the console handle
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // set the console text color
  SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
}

string toLowerCase(string str) {
  // easy way to convert a string to lowercase to make input case insensitive
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

void printOptions(const Player *player, const Map *map) {
  // Only showing the options that are possible according to the map
  cout << "\nAction: ";
  if (Map::roomExists(player->getRoom(), 'n')) {
    cout << "(N)orth, ";
  }
  if (Map::roomExists(player->getRoom(), 's')) {
    cout << "(S)outh, ";
  }
  if (Map::roomExists(player->getRoom(), 'e')) {
    cout << "(E)ast, ";
  }
  if (Map::roomExists(player->getRoom(), 'w')) {
    cout << "(W)est, ";
  }
  cout << "(M)ap, (H)elp";
  if (player->getHarpoons() > 0) {
    cout << ", shoot ha(R)poon";
  }
  if (player->getNets() > 0) {
    cout << ", use ne(T)";
  }
  cout << ", Q)uit: ";
}
