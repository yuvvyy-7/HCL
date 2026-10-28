#include <iostream>
using namespace std;

struct Player {
    string name;
    int score;
};

void addPlayer(Player list[], int& count, string name, int score) {
    list[count].name = name;
    list[count].score = score;
    count++;
}

void showLeaderboard(Player list[], int count) {
    cout << "\n--- Leaderboard ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << list[i].name << " - " << list[i].score << endl;
    }
}

int main() {
    const int MAX = 10;
    Player leaderboard[MAX];
    int count = 0;

    addPlayer(leaderboard, count, "Asha", 95);
    addPlayer(leaderboard, count, "Ravi", 80);

    showLeaderboard(leaderboard, count);

    return 0;
}
