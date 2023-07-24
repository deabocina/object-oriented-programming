#include <iostream>
using namespace std;

// Write a function that takes an array of numbers and the size of the array as input,
// and removes duplicates from the array, updating the size accordingly.
// In the main function, the user inputs the initial size of the array.
// Write functions for array input and array output.

void inputArray(int arr[], int size) {
    cout << "Enter elements of the array:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void outputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void removeDuplicates(int arr[], int& size) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[newSize] = arr[i];
            newSize++;
        }
    }
    size = newSize;
}

int main() {
    int arr1[10], arr2[10];
    int size = 0, i;

    cout << "Enter the size of the array: ";
    cin >> size;

    inputArray(arr1, size);
    removeDuplicates(arr1, size);
    outputArray(arr1, size);

    return 0;
}