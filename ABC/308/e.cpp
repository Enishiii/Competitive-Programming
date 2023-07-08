#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int mex(int a, int b, int c) {
    for (int i = 0; i < 3; ++i) {
        if (i != a && i != b && i != c) return i;
    }
    return 3;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    string s;
    cin >> s;

    vector cnt_l(n + 1, vector<int>(3));
    vector cnt_r(n + 1, vector<int>(3));

    for (int i = 0; i < n; ++i) {
        cnt_l[i+1] = cnt_l[i];
        if (s[i] == 'M') cnt_l[i+1][a[i]]++;
    }

    for (int i = n-1; i >= 0; --i) {
        cnt_r[i] = cnt_r[i+1];
        if (s[i] == 'X') cnt_r[i][a[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'E') continue;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans += (ll)cnt_l[i][j] * cnt_r[i+1][k] * mex(j, a[i], k);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
