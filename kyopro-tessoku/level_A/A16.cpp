#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for (int i = 2; i <= n; ++i) cin >> a[i];
    for (int i = 3; i <= n; ++i) cin >> b[i];

    vector<int> dp(n+1);
    dp[1] = 0;
    dp[2] = a[2];
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i-1] + a[i], dp[i-2] + b[i]);
    }
    cout << dp[n] << endl;

    return 0;
}
