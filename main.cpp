#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    while (true) {
        cout << " **************2048**************" << endl;
        cout << " 1. enter start to play a new game. " << endl;
        cout << " 2. enter close to exit. " << endl;
        cout << " 3. enter record to watch the records list" << endl;
        Record record;
        string command;
        cin >> command;
        if (command == "start") {
            Game newGame;
            newGame.playGame();
        } else if (command == "record") {
            record.print();
        } else if (command == "close") {
            exit(0);
        } else {
            cout << "wrong order" << endl;
        }
    }
}