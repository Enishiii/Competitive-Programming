#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> f(n+1);
    for (int a = 1; a < n; ++a) {
        for (int b = 1; a*b < n; ++b) {
            f[a*b]++;
        }
    }

    long long ans = 0;
    for (int x = 1; x < n; ++x) {
        ans += f[x] * f[n-x];
    }
    cout << ans << endl;

    return 0;
}