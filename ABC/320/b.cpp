// 問題文
// 文字列S が与えられます。S の連続する部分文字列のうち、回文であるものの長さの最大値を求めてください。
// ただし、S の連続する部分文字列であって回文であるものは常に存在します。

// 制約
// S は長さ2 以上100 以下の英大文字からなる文字列

#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            string t = s.substr(i, j - i);
            if (isPalindrome(t)) {
                ans = max(ans, j - i);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
