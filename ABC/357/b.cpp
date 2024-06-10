#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isUpperCaseDominant(const string& s) {
    int lowerCount = count_if(s.begin(), s.end(), ::islower);
    return lowerCount * 2 < s.size();
}

string unifyStringCase(string s) {
    if (isUpperCaseDominant(s)) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    return s;
}

int main() {
    string s;
    cin >> s;

    cout << unifyStringCase(s) << endl;

    return 0;
}
