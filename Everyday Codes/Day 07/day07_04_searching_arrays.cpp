/**
 * File: day07_04_searching_arrays.cpp
 * Topic: Searching in Arrays (Linear Search vs. Binary Search)
 * 
 * Concepts:
 *   1. Linear Search:
 *      - Scans the array element-by-element from left to right.
 *      - Works on ANY array (unsorted or sorted).
 *      - Time Complexity: O(n) (checks up to n elements).
 * 
 *   2. Binary Search:
 *      - Repeatedly divides a SORTED array in half.
 *      - Requires the array to be SORTED first!
 *      - Time Complexity: O(log n) (drastically faster for large data).
 */

#include <iostream>
using namespace std;

// 1. LINEAR SEARCH (Works on unsorted arrays)
int linearSearch(int arr[], int size, int target) {
    cout << "\n[Linear Search] Looking for " << target << ":" << endl;
    for (int i = 0; i < size; i++) {
        cout << "  Checking index " << i << " (value: " << arr[i] << ")..." << endl;
        if (arr[i] == target) {
            return i; // Found! Return the index
        }
    }
    return -1; // Not found after checking every element
}


// 2. BINARY SEARCH (Requires array to be SORTED)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int step = 1;

    cout << "\n[Binary Search] Looking for " << target << " in sorted array:" << endl;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Find midpoint safely
        cout << "  Step " << step++ << ": left=" << left 
             << ", right=" << right << ", mid=" << mid 
             << " (value: " << arr[mid] << ")" << endl;

        // Condition 1: Target is found at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // Condition 2: Target is smaller, discard the right half
        if (target < arr[mid]) {
            cout << "    -> " << target << " < " << arr[mid] << ", search LEFT half" << endl;
            right = mid - 1;
        }
        // Condition 3: Target is larger, discard the left half
        else {
            cout << "    -> " << target << " > " << arr[mid] << ", search RIGHT half" << endl;
            left = mid + 1;
        }
    }

    return -1; // Target not present in the array
}

// MAIN DEMONSTRATION
int main() {
    cout << "=== Array Searching Demo: Linear vs. Binary Search ===" << endl;

    // Part 1: Linear Search on Unsorted Scores
    int unsortedScores[] = {70, 95, 60, 88, 80};
    int n1 = 5;

    cout << "\nUnsorted array: ";
    for (int i = 0; i < n1; i++) cout << unsortedScores[i] << " ";
    cout << endl;

    int target1 = 88;
    int result1 = linearSearch(unsortedScores, n1, target1);

    if (result1 != -1) {
        cout << ">> Found " << target1 << " at index " << result1 << endl;
    } else {
        cout << ">> " << target1 << " not found in array." << endl;
    }

    // Part 2: Binary Search on Sorted Scores
    // Notice: The array MUST be sorted (e.g., using insertionSort from Day 07_02)
    int sortedScores[] = {60, 70, 80, 88, 95};
    int n2 = 5;

    cout << "\nSorted array:   ";
    for (int i = 0; i < n2; i++) cout << sortedScores[i] << " ";
    cout << endl;

    int target2 = 88;
    int result2 = binarySearch(sortedScores, n2, target2);

    if (result2 != -1) {
        cout << ">> Found " << target2 << " at index " << result2 << endl;
    } else {
        cout << ">> " << target2 << " not found in array." << endl;
    }

    // Part 3: Searching for an item not in the array
    int missingTarget = 99;
    int result3 = binarySearch(sortedScores, n2, missingTarget);
    if (result3 != -1) {
        cout << ">> Found " << missingTarget << " at index " << result3 << endl;
    } else {
        cout << ">> " << missingTarget << " not found in array (correctly returned -1)." << endl;
    }

    return 0;
}
