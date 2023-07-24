#include <iostream>
using namespace std;

// Write a function that returns a reference to the first element of the array that is greater than zero.
// Using the return value of the function as an lvalue in the main function, change the value of that element to zero.

int& findGreaterThanZero(int array[]) {
    for (int i = 0; i < 5; i++) {
        if (array[i] > 0)
            return array[i];
    }
}

int main() {
    int array[5] = { 0, 0, 5, 6, 8 };
    cout << findGreaterThanZero(array);

    return 0;
}