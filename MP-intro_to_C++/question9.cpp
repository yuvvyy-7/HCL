// Implement a dynamic array class or wrapper using new[] and delete[] in C++. Ensure
// that allocated memory is freed inside the destructor to prevent memory leaks.


#include <iostream>
using namespace std;

class DynamicArray {
    public:
        int* arr;

    DynamicArray() {
        arr = new int[5];
        cout << "Array memory created on the heap!\n";
    }

    ~DynamicArray() {
        delete[] arr;
        cout << "Array memory cleaned up safely!\n";
    }
};

int main() {

{
    DynamicArray myArray;
    myArray.arr[0] = 99;
    cout << "Stored value: " << myArray.arr[0] << "\n";
}


return 0;
}