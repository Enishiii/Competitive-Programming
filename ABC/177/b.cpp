#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int ans = 10000;
    int n = s.size(), m = t.size();
    
    for (int i = 0; i <= n-m; ++i) {
        int cur = 0;
        string u = s.substr(i, m);
        for (int j = 0; j < m; ++j) {
            if (t[j] != u[j]) cur++;
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;

    return 0;
}
