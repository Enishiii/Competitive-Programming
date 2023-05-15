#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, k, x;
    cin >> n >> k >> x;
    
    vector<int> a(n);
    long long ans = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
        m += a[i]/x;
    }
    m = min(m, k);
    ans -= m*x;
    k -= m;

    for (int i = 0; i < n; ++i) a[i] %= x;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
        if (k == 0) break;
        ans -= a[i];
        k--;
    }
    cout << ans << endl;
    
    return 0;
}