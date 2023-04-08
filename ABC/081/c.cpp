#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a-1]++;
    }
    sort(cnt.begin(), cnt.end());

    int ans = 0;
    for (int i = 0; i < n-k; ++i) {
        ans += cnt[i];
    }
    cout << ans << endl;

    return 0;
}
