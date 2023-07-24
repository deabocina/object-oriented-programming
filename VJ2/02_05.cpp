#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Write a function that translates English sentences into Pig Latin.The rules are as follows :
// (a) If a word starts with a vowel, add "hay" to the end of the word.
// (b) Otherwise, move all consonants from the beginning of the word to the end, and add "ay" at the end.
// Sentences should be stored in a vector, and then a randomly selected sentence from the vector should be translated.
// Example : "What time is it?" is translated as "atwhay imetay ishay ithay?"

string translateWord(const string& word) {
    if (word.empty()) {
        return "";
    }

    if (word[0] == 'A' || word[0] == 'a'
        || word[0] == 'E' || word[0] == 'e'
        || word[0] == 'I' || word[0] == 'i'
        || word[0] == 'O' || word[0] == 'o'
        || word[0] == 'U' || word[0] == 'u') {
        return word + "hay";
    }
    else {
        int i = 0;
        while (i < word.length() && !(word[i] == 'A' || word[i] == 'a'
            || word[i] == 'E' || word[i] == 'e'
            || word[i] == 'I' || word[i] == 'i'
            || word[i] == 'O' || word[i] == 'o'
            || word[i] == 'U' || word[i] == 'u')) {
            i++;
        }
        return word.substr(i) + word.substr(0, i) + "ay";
    }
}

string translate(const string& sentence) {
    string result;
    string word;
    for (char ch : sentence) {
        if (ch == ' ' || ch == '.' || ch == ',' || ch == '!' || ch == '?') {
            if (!word.empty()) {
                result += translateWord(word) + ch;
                word = "";
            }
            else {
                result += ch;
            }
        }
        else {
            word += ch;
        }
    }

    return result;
}

int main() {
    srand(time(NULL));
    vector<string> sentences = { "What time is it?" };
    int random = rand() % sentences.size();

    string translatedSentence = translate(sentences[random]);
    cout << "Original sentence: " << sentences[random] << endl;
    cout << "Translated sentence: " << translatedSentence << endl;

    return 0;
}