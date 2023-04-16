#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        char t;
        int a;
        cin >> t >> a;

        if (t == '+') ans += a;
        else if (t == '-') ans -= a;
        else if (t == '*') ans *= a;

        if (ans < 0) ans += 10000;
        ans %= 10000;
        cout << ans << endl;
    }
    
    return 0;
}
