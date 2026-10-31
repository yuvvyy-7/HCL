#include <iostream>
using namespace std;

int largest(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {

int x = 20;
int y = 40;

cout << largest(x,y);


return 0;
}