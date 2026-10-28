#include <iostream>
using namespace std;

int main() {
    string playerName;
    int score;

    cout << "Enter player name: ";
    getline(cin, playerName);

    cout << "Enter score: ";
    cin >> score;

    cout << playerName << " scored " << score << " points." << endl;

    return 0;
}
