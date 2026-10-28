#include <iostream>
using namespace std;

int main() {
    int score = 95;
    int *scorePtr = &score;   // scorePtr holds the address of score

    cout << "Value of score: " << score << endl;
    cout << "Address of score: " << &score << endl;
    cout << "scorePtr holds: " << scorePtr << endl;
    cout << "Value scorePtr points to: " << *scorePtr << endl;

    *scorePtr = 100;   // changes score through the pointer
    cout << "score is now: " << score << endl;

    return 0;
}
