#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Write a function that takes user input strings, stores them in a vector of strings, reverses each string, and then sorts the vector based on the reversed strings.

void input(vector<string>& vector, int size) {
    string str;

    for (int i = 0; i < size; i++) {
        cin >> str;
        vector.push_back(str);
    }
}

void reverseStrings(vector<string>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        reverse(vector[i].begin(), vector[i].end());
    }
}

void sortStrings(vector<string>& vector) {
    sort(vector.begin(), vector.end());
}

int main() {
    vector<string> vector;
    int size;

    cout << "Enter the size of the vector: ";
    cin >> size;
    input(vector, size);
    reverseStrings(vector);
    sortStrings(vector);

    for (string i : vector) {
        cout << i << " ";
    }

    return 0;
}