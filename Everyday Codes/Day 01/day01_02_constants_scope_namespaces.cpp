#include <iostream>
using namespace std;

const int MAX_PLAYERS = 10;   // named constant, global scope

namespace Game {
    const int BONUS_POINTS = 50;
}

int main() {
    int localScore = 100;      // local scope: only visible inside main

    cout << "Max players allowed: " << MAX_PLAYERS << endl;
    cout << "Bonus points: " << Game::BONUS_POINTS << endl;
    cout << "Local score: " << localScore << endl;

    return 0;
}
