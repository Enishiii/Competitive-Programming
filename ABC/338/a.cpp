#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

bool isValidString(const string& s) {
    if (s.empty() || !isupper(s[0])) return false;

    return all_of(s.begin() + 1, s.end(), ::islower);
}

int main() {
    string s;
    cin >> s;

    cout << (isValidString(s) ? "Yes" : "No") << endl;

    return 0;
}
