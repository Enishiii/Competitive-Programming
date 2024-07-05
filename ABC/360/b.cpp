#include <iostream>
using namespace std;

bool checkPatternMatch(const string& source, const string& target) {
    for (int windowSize = 1; windowSize < source.size(); ++windowSize) {
        for (int startIndex = 0; startIndex < windowSize; ++startIndex) {
            string constructedString = "";
            for (int currentIndex = startIndex; currentIndex < source.size(); currentIndex += windowSize) {
                constructedString += source[currentIndex];
            }

            if (constructedString == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string source, target;
    cin >> source >> target;

    if (checkPatternMatch(source, target)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
