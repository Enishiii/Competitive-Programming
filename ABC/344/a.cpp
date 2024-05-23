#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool isBetween = false;
    string ans = "";

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '|') {
            isBetween = (isBetween == true) ? false : true;
            continue;
        }

        if (!isBetween) {
            ans += s[i];
        }
    }
    cout << ans << endl;

    return 0;
}
