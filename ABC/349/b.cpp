#include <iostream>
#include <vector>
#include <array>
using namespace std;

string readInputString() {
    string inputString;
    cin >> inputString;
    return inputString;
}

array<int, 26> countCharOccurrences(const string& inputString) {
    array<int, 26> charCounts = {0};
    for (char c : inputString) {
        charCounts[c - 'a']++;
    }
    return charCounts;
}

array<int, 101> countTypeOccurrences(const array<int, 26>& charOccurrences) {
    array<int, 101> typeCounts = {0};
    for (int c : charOccurrences) {
        if (c > 0) {
            typeCounts[c]++;
        }
    }
    return typeCounts;
}

bool isGoodString(const array<int, 101>& typeOccurrences) {
    for (int count : typeOccurrences) {
        if (count != 0 && count != 2) {
            return false;
        }
    }
    return true;
}

void printIsGoodString(bool isGood) {
    cout << (isGood == true ? "Yes" : "No") << endl;
}

int main() {
    string inputString = readInputString();

    array<int, 26> charOccurrences = countCharOccurrences(inputString);

    array<int, 101> typeOccurrences = countTypeOccurrences(charOccurrences);

    printIsGoodString(isGoodString(typeOccurrences));

    return 0;
}
