#include "functions.hpp"

void input(vector<int>& vector, int size) {
    int temp = 0;

    for (int i = 0; i < size; i++) {
        cout << "Enter elements: ";
        cin >> temp;
        vector.push_back(temp);
    }
}

void inputInRange(vector<int>& vector, int& size, int lowerBound, int upperBound) {
    int temp = 0;

    for (;;) {
        cout << "Enter elements: ";
        cin >> temp;
        if (temp >= lowerBound && temp <= upperBound) {
            vector.push_back(temp);
            size++;
        }
        else {
            return;
        }
    }
}

void output(vector<int> vector, int size) {
    for (int i = 0; i < size; i++) {
        cout << vector[i] << " ";
    }
}