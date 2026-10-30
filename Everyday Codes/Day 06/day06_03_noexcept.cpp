#include <iostream>
using namespace std;

int addScores(int a, int b) noexcept {   // promises never to throw
    return a + b;
}

void riskyOperation() {
    throw runtime_error("something went wrong");
}

int main() {
    cout << "Sum: " << addScores(10, 20) << endl;

    cout << "noexcept(addScores(1,2)): " << noexcept(addScores(1, 2)) << endl;   // true (1)

    try {
        riskyOperation();
    } catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }

    return 0;
}
