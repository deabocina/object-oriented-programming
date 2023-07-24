#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Read a sentence as a string.Write a function that removes all spaces that are before punctuation marks 
// and adds spaces after punctuation marks if they are missing.
// Example: For the sentence "I would ,if possible , write this sentence correctly .", 
// the corrected sentence would be : "I would, if possible, write this sentence correctly."

void correction(string& sentence) {
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == '.' || sentence[i] == ',' || sentence[i] == ':' || sentence[i] == ';' || sentence[i] == '!' || sentence[i] == '?') {
            if (i != 0) {
                if (sentence[i - 1] == ' ') {
                    sentence.erase(sentence.begin() + i - 1);
                    i--;
                }
            }
            if (sentence[i + 1] != ' ') {
                sentence.insert(sentence.begin() + i + 1, ' ');
            }
        }
    }
}

int main() {
    string sentence = "I would ,if possible , write this sentence correctly .\n";

    correction(sentence);
    cout << sentence;
    return 0;
}
