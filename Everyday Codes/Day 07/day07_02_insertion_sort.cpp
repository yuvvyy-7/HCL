#include <iostream>
using namespace std;

void insertionSort(int scores[], int n) {
    for (int i = 1; i < n; i++) {
        int key = scores[i];
        int j = i - 1;
        while (j >= 0 && scores[j] < key) {   // descending order: highest score first
            scores[j + 1] = scores[j];
            j--;
        }
        scores[j + 1] = key;
    }
}

void iSort(int scores[], int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(scores[j] < scores[j+1]) {
                int temp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = temp;
            }
        }   
    }
}

int main() {
    int scores[] = {70, 95, 80, 60, 88};
    int n = 5;

    //insertionSort(scores, n);
    iSort(scores, n);
    cout << "Sorted leaderboard (highest first): ";
    for (int i = 0; i < n; i++) cout << scores[i] << " ";
    cout << endl;

    return 0;
}
