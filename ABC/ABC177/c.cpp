#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    const int mod = 1000000007;

    long long ans = 0, x = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans+a[i]*x)%mod;
        x = (x+a[i])%mod;
    }
    cout << ans << endl;

    return 0;
}

