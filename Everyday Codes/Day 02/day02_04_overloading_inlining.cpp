#include <iostream>
using namespace std;

// Overloaded functions: same name, different parameter lists
void showScore(int score) {
    cout << "Score: " << score << endl;
}

void showScore(string name, int score) {
    cout << name << " - Score: " << score << endl;
}

inline int bonus(int score) {   // inline: compiler may substitute the call with the body
    return score + 10;
}

int main() {
    showScore(85);
    showScore("Asha", 95);
    cout << "With bonus: " << bonus(85) << endl;

    return 0;
}
