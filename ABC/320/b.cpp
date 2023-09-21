// 問題文
// 文字列S が与えられます。S の連続する部分文字列のうち、回文であるものの長さの最大値を求めてください。
// ただし、S の連続する部分文字列であって回文であるものは常に存在します。

// 制約
// S は長さ2 以上100 以下の英大文字からなる文字列

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 2; j <= n; ++j) {
            string t = s.substr(i, j);
            string u = t;
            reverse(u.begin(), u.end());
            if (t == u) {
                int m = t.size();
                ans = max(ans, m);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
