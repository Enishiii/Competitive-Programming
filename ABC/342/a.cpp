#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    char a = s[0];
    char b;
    int noA = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != a) {
            b = s[i];
            noA++;
        }
    }

    if (noA > 1) {
        cout << 1 << endl;
    } else {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == b) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
