#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void readFromFile() {
    ifstream file("numbers.txt");

    // (a) throw an exception if the file does not exist
    if (!file) {
        throw runtime_error("Unable to open file");
    }

    // (b) fill the vector with numbers from the file
    vector<int> numbers;
    int number;
    while (file >> number) {
        numbers.push_back(number);
    }

    // (c) count all numbers greater than 500
    int greaterThan500 = count_if(numbers.begin(), numbers.end(), [](int n) { return n > 500; });
    cout << "Numbers greater than 500: " << greaterThan500 << endl;

    // (d) find the minimum and maximum element
    int minElement = *min_element(numbers.begin(), numbers.end());
    int maxElement = *max_element(numbers.begin(), numbers.end());
    cout << "Min element: " << minElement << endl;
    cout << "Max element: " << maxElement << endl;

    // (e) remove numbers less than 300 from the vector
    numbers.erase(remove_if(numbers.begin(), numbers.end(), [](int n) { return n < 300; }), numbers.end());

    // (f) sort the remaining numbers in descending order
    sort(numbers.rbegin(), numbers.rend());

    cout << "Remaining numbers: ";
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main() {
    try {
        readFromFile();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}