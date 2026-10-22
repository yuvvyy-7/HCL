//Q.5. Create three overloaded versions or variations of a function named increment that
// demonstrate passing an argument by value, by pointer, and by reference. Trace the
// value in main() after each call.

#include <iostream>
using namespace std;

void increment(int num) {
    num++;
};

void increment(int* p) {
    (*p)++;
}

void increment(long& num) {
    num++;
}

int main() {

int num1 = 1;
increment(num1);
cout << num1 << endl;

int num2 = 1;
int *p = &num2;
increment(p);
cout << num2 << endl;

long num3 = 1;
increment(num3);
cout << num3 << endl;


return 0;
}