#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Write a function that counts how many occurrences of a given substring exist in a string using standard library functions.

int countOccurrences(string str, string subStr) {
    int count = 0, subStrLength = subStr.length(), strLength = str.length();

    for (int i = 0; i <= strLength - subStrLength; i++) {
        int j = 0;
        for (j = 0; j < subStrLength; j++) {
            if (str[i + j] != subStr[j]) {
                break;
            }
        }
        if (j == subStrLength) {
            count++;
        }
    }
    return count;
}

int main() {
    string str, subStr;

    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter the substring: ";
    cin >> subStr;
    cout << countOccurrences(str, subStr);

    return 0;
}