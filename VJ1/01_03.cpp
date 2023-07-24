#include <iostream>
using namespace std;

// Write a function that returns an array of int values of size n, where each
// element is the sum of its two predecessors. The first and second elements in
// the array are both ones. In the main function, print the resulting array and free the memory.

int* generateArray(int n) {
    int* arr = new int[n];

    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i < n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr;
}

int main() {
    int* arr;
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    arr = generateArray(n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}