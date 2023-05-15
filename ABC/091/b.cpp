#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    cin >> m;
    vector<string> t(m);
    for (int i = 0; i < m; ++i) cin >> t[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int current = 0;
        for (int j = 0; j < n; ++j) {
            if (s[i] == s[j]) current++;
        }
        for (int k = 0; k < m; ++k) {
            if (s[i] == t[k]) current--;
        }
        ans = max(ans, current);
    }
    cout << ans << endl;

    return 0;
}