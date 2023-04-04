#include <iostream>
using namespace std;

const long long INF = 1000000000000000000;

int main() {
    int n;
    cin >> n;

    long long ans = 1;
    bool ng = false;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        if (a == 0) {
            cout << 0 << endl;
            return 0;
        }

        if (ng || INF / ans < a) {
            ng = true;
        }
        ans *= a;
    }
    if (ng) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}