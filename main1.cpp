#include <iostream>
using namespace std;

void showScore(int score) {
    cout << "Score: " << score << endl;
}

void showScore(string name, int score) {
    cout << name << " - Score: " << score << endl;
}

inline int bonus(int score) {
    return score + 10;
}


int main() {


// int sum = 0;
// int num;
// do{
//     cout << "enter num: ";
//     cin >> num;
//     sum += num;
// } while(num != 0);

// cout << "Sum: " << sum;

showScore(85);
showScore("Yuvraj", 67);

cout << "With bonus: " << bonus(89) << endl;

return 0;
}