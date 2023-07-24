#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;

// Write functions for input and output of a vector of numbers. Put the function prototypes in a.hpp file and the implementation in a.cpp file.
//
// For inputting the vector, write two functions :
// A function with parameters as a reference to the vector and the number of elements in the vector.
// A function with parameters as a reference to the vector and the range of values within which the vector elements should lie. The elements 
// of the vector are inputted in the function until a number outside the specified range is entered.

int main() {
    vector<int> vector;
    int size = 0, lowerBound = 0, upperBound = 0;

    cout << "Enter the size of the vector: ";
    cin >> size;
    input(vector, size);

    cout << "Enter the lower bound: ";
    cin >> lowerBound;
    cout << "Enter the upper bound: ";
    cin >> upperBound;

    inputInRange(vector, size, lowerBound, upperBound);
    output(vector, size);

    return 0;
}