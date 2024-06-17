#include <iostream>
using namespace std;

bool isAtCoderLand(string s, string t) {
    return (s == "AtCoder") && (t == "Land");
}

int main() {
    string s, t;
    cin >> s >> t;

    if (isAtCoderLand(s, t)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
