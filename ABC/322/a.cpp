/*
問題文
A, B, C からなる長さN の文字列S が与えられます。
S の中で ABC が(連続な)部分文字列として初めて現れる位置を答えてください。すなわち、以下の条件を全て満たす整数n のうち最小のものを答えてください。
    ・1≤n≤N−2
    ・S のn 文字目からn+2 文字目までを取り出して出来る文字列は ABC である。
ただし、ABC がS に現れない場合は -1 を出力してください。

制約
3≤N≤100
S は A, B, C からなる長さN の文字列
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n-2; ++i) {
        string t = s.substr(i, 3);
        if (t == "ABC") {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
