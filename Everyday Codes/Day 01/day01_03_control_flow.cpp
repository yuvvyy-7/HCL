#include <iostream>
using namespace std;

int main() {
    int score = 85;

    // if/else: grade the score
    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 75) {
        cout << "Grade: B" << endl;
    } else {
        cout << "Grade: C" << endl;
    }

    // switch: menu choice
    int choice = 2;
    switch (choice) {
        case 1:
            cout << "New Game" << endl;
            break;
        case 2:
            cout << "Show Leaderboard" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    // loop: print top 3 placeholder scores
    for (int i = 1; i <= 3; i++) {
        cout << "Rank " << i << endl;
    }

    return 0;
}
