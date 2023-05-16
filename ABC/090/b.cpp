/* 問題文
A 以上B 以下の整数のうち、回文数となるものの個数を求めてください。 ただし、回文数とは、先頭に0 をつけない10 進表記を文字列として見たとき、前から読んでも後ろから読んでも同じ文字列となるような正の整数のことを指します。

制約
10000 ≤ A ≤ B ≤ 99999
入力はすべて整数である */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = a; i <= b; ++i) {
        string s = to_string(i);

        // ひっくり返した文字列と一致するかで回文かを判定
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) ans++;
    }
    cout << ans << endl;

    return 0;
}
