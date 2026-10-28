#include <iostream>
using namespace std;

void addBonusByValue(int score) {
    score += 10;   // only changes the local copy
}

void addBonusByReference(int& score) {
    score += 10;   // changes the caller's variable
}

void addBonusByPointer(int* score) {
    *score += 10;  // changes the caller's variable through the address
}

int main() {
    int s1 = 50, s2 = 50, s3 = 50;

    addBonusByValue(s1);
    addBonusByReference(s2);
    addBonusByPointer(&s3);

    cout << "By value: " << s1 << endl;       // 50 (unchanged)
    cout << "By reference: " << s2 << endl;   // 60
    cout << "By pointer: " << s3 << endl;     // 60

    return 0;
}
