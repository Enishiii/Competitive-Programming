#include <iostream>
using namespace std;

string readInputString() {
    string input;
    cin >> input;
    return input;
}

void printMatchingPositions(const string& target, const string& source) {
    int targetIndex = 0;
    for (int i = 0; i < source.size(); i++) {
        if (source[i] == target[targetIndex]) {
            cout << i + 1 << " ";
            targetIndex++;
        }
    }
    cout << endl;
}

int main() {
    string target = readInputString();
    string source = readInputString();

    printMatchingPositions(target, source);

    return 0;
}
