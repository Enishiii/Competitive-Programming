#include <iostream>
#include <algorithm>
using namespace std;

int func(string s, string t) {
    int ans = 0;
    for (int c = 'a'; c <= 'z'; ++c) {
        bool foundS = false, foundT = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) foundS = true;
        }
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == c) foundT = true;
        }
        if (foundS && foundT) ans++;
    }
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int tmp = func(s.substr(0, i), s.substr(i));

        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}