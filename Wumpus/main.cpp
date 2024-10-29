#include <iostream>
#include <windows.h>
using namespace std;
void help();
void setup();

int main()
{
    setup();
    help();
    return 0;
}

void help() {
    cout << "Welcome to hunt the Kraken.  You are a deep sea scuba diver seeking to kill the Kraken before you run out of oxygen. The sea floor is divided into 30 spaces in a 5 high 6 wide rectangle. Each space is connected to 4 others." << endl << endl;
    cout << "Hazards:" << endl << "Whirlpool -  One space has a whirlpool. If you go there, you will be whisked away to a random space and will lose 5 oxygen." << endl << "Riptide - Two spaces have riptides. These will drown you and you will lose." << endl << endl;
    cout << "Kraken:" << endl << "The Kraken is not affected by hazards. The Kraken is usually asleep. If you shoot a Harpoon and miss, he might wake up and move to  an adjacent space. If you attempt to move into the Kraken's space, it eats you and you lose." << endl << endl;
    cout << "You:" << endl << "Each turn you may move or use a weapon."  << endl << "Moving: You can move one space North, South, East, or West if there is a room in that direction." << endl << "Oxygen: Each move consumes 1 Oxygen. If you run out of Oxygen you lose. There is one Oxygen tank that you can find." << endl << "Using Weapons: You can use the Harpoon to attack an adjacent space (you start with 2 harpoons and can find 2 more)." << endl << "If you hit the Kraken with a Harpoon, you win." << endl << "If you find the net, you can throw it to see if the Kraken is hiding in any of the nearest 3 spaces in the direction you choose. The net does not kill the Kraken." << endl << "You will be given hints indicating when a hazard or the Kraken is nearby." << endl;

}

void setup() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,
      FOREGROUND_BLUE);
}