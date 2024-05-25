#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> countChars(const string& inputString) {
    unordered_map<char, int> charCount;

    for (char c : inputString) {
        charCount[c]++;
    }

    return charCount;
}

int findUniqueCharIndex(const string& inputString) {
    int uniqueCharIndex = -1;

    unordered_map<char, int> charCount = countChars(inputString);
    
    for (int i = 0; i < inputString.size(); ++i) {
        if (charCount[inputString[i]] == 1) {
            uniqueCharIndex = i + 1;
            return uniqueCharIndex;
        }
    }
}

int main() {
    string inputString;
    cin >> inputString;

    int uniqueCharIndex = findUniqueCharIndex(inputString);

    cout << uniqueCharIndex << endl;

    return 0;
}
