#include <iostream>
using namespace std;

string turnIntoTDLFrom(const string& str) {
    int dotPosition = -1;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] != '.') continue;

        dotPosition = i;
        break;
    }

    return str.substr(dotPosition + 1);
}

int main() {
    string inputString;
    cin >> inputString;

    string topLevelDomain = turnIntoTDLFrom(inputString);

    cout << topLevelDomain << endl;

    return 0;
}
