#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int cnt = 0, ans = 0;
    for (int i = 0; i < d; ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == 'x') ok = false;
        }

        if (ok) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;

    return 0;
}
