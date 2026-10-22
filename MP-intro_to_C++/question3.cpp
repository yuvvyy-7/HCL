//Q.3. Write a function that takes two integer pointers as arguments and swaps the values
// stored in those memory addresses without using additional helper functions.


#include <iostream>
using namespace std;

void swapNum(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
int num1, num2;
cin >> num1 >> num2;

int *p1 = &num1;
int *p2 = &num2;

swapNum(p1, p2);

cout << num1 << " " << num2;

return 0;
}