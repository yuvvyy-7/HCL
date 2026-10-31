#include <iostream>
using namespace std;

const int MAX = 10;

void insertAt(int scores[], int& size, int index, int value) {
    if (size >= MAX || index < 0 || index > size) return;
    for (int i = size; i > index; i--) {
        scores[i] = scores[i - 1];   // shift right to make room
    }
    scores[index] = value;
    size++;
}

void removeAt(int scores[], int& size, int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size - 1; i++) {
        scores[i] = scores[i + 1];   // shift left to close the gap
    }
    size--;
}

int main() {
    int scores[MAX] = {80, 95, 70};   // initial scores
    int count = 3;

    insertAt(scores, count, 1, 88);   // insert 88 at index 1
    removeAt(scores, count, 0);       // remove the first entry

    for (int i = 0; i < count; i++) cout << scores[i] << " ";
    cout << endl;

    return 0;
}
