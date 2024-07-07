#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    int x = 0, y = 0;
    string s;

    cin >> s;
    s += '0';

    for (int i = 0; i <= n; ++i) {
        if (s[i] == '0') {
            ans = max(ans, max(x + y - m, y));
            x = 0, y = 0;
        }
        if (s[i] == '1') x++;
        if (s[i] == '2') y++;
    }
    cout << ans << endl;

    return 0;
}
