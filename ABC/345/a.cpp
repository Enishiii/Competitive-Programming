#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool isLeftRightArrow = true;

    if (s[0] != '<') isLeftRightArrow = false;

    if (s[s.size()-1] != '>') isLeftRightArrow = false;

    for (int i = 1; i < s.size()-1; ++i) {
        if (s[i] != '=') isLeftRightArrow = false;
    }

    if (isLeftRightArrow) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
