#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    sort(c.begin(), c.end());
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        ans = (ans * max(c[i]-i, 0)) % mod;
    }
    cout << ans << endl;
    
    return 0;
}
