#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void processNumbers(vector<int> numbers) {
    //(a) find the first odd number if it exists (find_if)
    auto firstOdd = find_if(numbers.begin(), numbers.end(), [](int i) { return (i % 2) != 0; });
    if (firstOdd != numbers.end()) {
        cout << "First odd number: " << *firstOdd << endl;
    }
    else {
        cout << "No odd numbers found" << endl;
    }

    //(b) find the total count of odd numbers (count_if)
    int oddCount = count_if(numbers.begin(), numbers.end(), [](int i) { return (i % 2) != 0; });
    cout << "Total count of odd numbers: " << oddCount << endl;

    //(c) replace all powers of 2 with 2 (replace_if)
    replace_if(numbers.begin(), numbers.end(), [](int i) { return (i & (i - 1)) == 0; }, 2);

    //(d) print all even numbers in ascending order, followed by all odd numbers in ascending order (sort)
    sort(numbers.begin(), numbers.end(), [](int a, int b) { return a < b; });
    cout << "Even numbers: ";
    for (int i : numbers) {
        if (i % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl << "Odd numbers: ";
    for (int i : numbers) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    processNumbers(numbers);
    return 0;
}