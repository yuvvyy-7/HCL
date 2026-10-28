#include <iostream>
using namespace std;

struct Player {
    string name;
    int score;
};

int main() {
    int scores[3] = {80, 95, 70};

    cout << "First score: " << scores[0] << endl;
    cout << "Same value via pointer: " << *scores << endl;   // array name decays to pointer
    cout << "Second score via pointer arithmetic: " << *(scores + 1) << endl;

    Player p1;
    p1.name = "Asha";
    p1.score = 95;
    cout << p1.name << " scored " << p1.score << endl;

    return 0;
}
