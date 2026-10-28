#include <iostream>
using namespace std;

int main() {
    int score, choice, ranks;

    // Input score from the user
    cout << "Enter your score (0-100): ";
    cin >> score;

    // if/else: grade the score
    if (score >= 90) {
        cout << "Grade: A" << endl;
    } else if (score >= 75) {
        cout << "Grade: B" << endl;
    } else {
        cout << "Grade: C" << endl;
    }

    // Input menu choice from the user
    cout << "\nMenu:" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Show Leaderboard" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    // switch: process menu choice
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

    // Input number of ranks to display
    cout << "\nEnter the number of ranks to display: ";
    cin >> ranks;

    // loop: display ranks
    if (ranks > 0) {
        for (int i = 1; i <= ranks; i++) {
            cout << "Rank " << i << endl;
        }
    } else {
        cout << "Please enter a positive number." << endl;
    }

    return 0;
}