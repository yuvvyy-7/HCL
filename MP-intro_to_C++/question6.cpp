//Q.6. Write an inline function maxOfThree(int a, int b, int c) that returns the largest value.
// Explain the trade-offs in memory and execution speed compared to a non-inline function.


#include <iostream>
using namespace std;

inline int maxOfThree(int a, int b, int c) {
    int maxVal = a;

    if (b > maxVal) {
        maxVal = b;
    }
    if (c > maxVal) {
        maxVal = c;
    }

    return maxVal;
}


int main() {

int a = 20, b = 40, c = 50;
cout << maxOfThree(a, b, c);

return 0;
}