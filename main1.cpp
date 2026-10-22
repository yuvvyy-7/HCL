#include <iostream>
using namespace std;

int main() {


int sum = 0;
int num;
do{
    cout << "enter num: ";
    cin >> num;
    sum += num;
} while(num != 0);

cout << "Sum: " << sum;

return 0;
}