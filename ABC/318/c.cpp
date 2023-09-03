#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    for (int i = 0; i < n; ++i) cin >> f[i];

    vector<ll> copy = f;
    sort(copy.rbegin(), copy.rend());

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll maxCostWithinD = 0;
        for (int j = i; j < i + d && j < n; ++j) {
            maxCostWithinD += copy[j];
        }

        if (maxCostWithinD > p) {
            ans += p;
            i += d - 1;
        } else {
            for (int j = i; j < i + d && j < n; ++j) {
                ans += copy[j];
            }
            i += d - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
