#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') cnt1++;
        if (s[i] == '0') cnt0++;
    }
    int ans = min(cnt1, cnt0) * 2;
    cout << ans << endl;

    return 0;
}