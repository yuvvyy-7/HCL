// Q.2. Implement a program that reads an integer N from standard input and uses nested loops
// to print a pyramid pattern of stars of height N.


#include <iostream>
using namespace std;

int main() {

int N;
cin >> N;

for(int i = 0; i < N; ++i) {
    for(int j = N-1 - i; j > 0; --j) {
        cout << " ";
    }

    for(int j = (2 * i + 1); j > 0; --j) {
        cout << "*";
    }

    for(int j = N-1 - i; j > 0; --j) {
        cout << " ";
    }
    cout << "\n";
}


return 0;
}