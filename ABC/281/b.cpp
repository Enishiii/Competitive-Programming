#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool first = isupper(s[0]);
    string t = s.substr(1, s.size()-2);
    bool num = t[0] != '0' && isdigit(t[0]);
    for (int i = 1; i < t.size(); ++i) {
        if (!isdigit(t[i])) num = false;
    }
    bool last = isupper(s.back());

    if (first && num && last) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
