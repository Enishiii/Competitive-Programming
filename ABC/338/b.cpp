#include <iostream>
#include <unordered_map>
using namespace std;

char findMostFrequentChar(const string& s) {
    unordered_map<char, int> charCounts;
    for (char c : s) {
        charCounts[c]++;
    }

    char mostFrequentChar;
    int maxCount = 0;
    for (auto const&[character, count] : charCounts) {
        if (count > maxCount || (count == maxCount && character < mostFrequentChar)) {
            maxCount = count;
            mostFrequentChar = character;
        }
    }
    return mostFrequentChar;
}

int main() {
    string s;
    cin >> s;

    char result = findMostFrequentChar(s);
    cout << result << endl;

    return 0;
}
