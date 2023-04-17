#include <iostream>
using namespace std;

int main() {
    int n, m, b;
    cin >> n >> m >> b;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ans += (long long)a*m;
    }
    for (int i = 0; i < m; ++i) {
        int c;
        cin >> c;
        ans += (long long)c*n;
    }
    ans += (long long)b * n * m;
    cout << ans << endl;

    return 0;
}
