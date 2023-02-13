#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n);
    for (int i = 0; i < n+1; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long lft = min(a[i], b[i]);

        ans += lft;
        a[i] -= lft;
        b[i] -= lft;

        long long rht = min(a[i+1], b[i]);

        ans += rht;
        a[i+1] -= rht;
        b[i] -= rht;
    }
    cout << ans << endl;

    return 0;
}