#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int cnt_bar = 0, cnt_dango = 0;
    int ans = -1, cur = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') {
            cnt_dango++;
            if (s[i+1] == 'o') cur++;
            else cur = 1;
        } else if (s[i] == '-'){
            cnt_bar++;
        }
        ans = max(ans, cur);
    }

    if (cnt_bar && cnt_dango) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
