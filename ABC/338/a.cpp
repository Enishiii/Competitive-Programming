#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool startsWithUpper(const string& s) {
    return !s.empty() && isupper(s[0]);
}

bool restAreLower(const string& s) {
    for (int i = 1; i < s.size(); ++i) {
        if (!islower(s[i])) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    if (startsWithUpper(s) && restAreLower(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
