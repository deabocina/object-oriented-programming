#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Using STL functions, sort the vector, insert 0 before the smallest element, and calculate the sum of all elements after the largest element.

void input(vector<int>& vector, int size) {
    int temp = 0;

    for (int i = 0; i < size; i++) {
        cout << "Enter elements:\n";
        cin >> temp;
        vector.push_back(temp);
    }
}

void sortAndInsert(vector<int>& vector, int size) {
    int minElement = 0, maxElement = 0, sum = 0;

    minElement = *min_element(vector.begin(), vector.end());
    maxElement = *max_element(vector.begin(), vector.end());

    for (int i = 0; i < size; i++) {
        if (minElement == vector[i]) {
            vector.insert(vector.begin() + i, 0);
            size++;
            break;
        }
    }

    for (int i = 0; i < size; i++) {
        if (maxElement == vector[i]) {
            vector.insert(vector.begin() + i + 1, accumulate(vector.begin(), vector.end(), 0));
            break;
        }
    }
}

void output(const vector<int>& vector, int size) {
    for (int i : vector) {
        cout << i << " ";
    }
}

int main() {
    vector<int> vector;
    int size = 0;

    cout << "Enter the size of the vector: ";
    cin >> size;

    input(vector, size);
    sortAndInsert(vector, size);
    output(vector, size);

    return 0;
}