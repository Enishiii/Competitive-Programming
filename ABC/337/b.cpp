#include <iostream>
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

    if (ranges::is_sorted(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
