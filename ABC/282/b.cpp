#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            bool ok = true;
            for (int k = 0; k < m; ++k) {
                if (s[i][k] == 'x' && s[j][k] == 'x') ok = false;
            }
            if (ok) ans++;
        }
    }
    cout << ans / 2 << endl;

    return 0;
}
