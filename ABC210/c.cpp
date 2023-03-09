#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    int ans = 0;
    map<int, int> mp;
    int now = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[c[i]] == 0) now++;
        mp[c[i]]++;
        if (i >= k) {
            mp[c[i-k]]--;
            if (mp[c[i-k]] == 0) now--;
        }
        ans = max(ans, now);
    }
    cout << ans << endl;

    return 0;
}