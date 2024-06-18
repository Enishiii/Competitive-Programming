#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    // if (regex_match(s, regex("A*B*C*"))) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }

    // if (ranges::is_sorted(s)) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }

    for (int a = 0; a <= s.size(); ++a) {
        for (int b = 0; b <= s.size() - a; ++b) {
            int c = s.size() - a - b;
            if (s == string(a, 'A') + string(b, 'B') + string(c, 'C')) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
