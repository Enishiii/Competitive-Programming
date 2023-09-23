/*
問題文
英小文字からなる文字列S が与えられます。
S の先頭からa 文字目とb 文字目を入れ替えて得られる文字列を出力してください。

制約
S は英小文字からなる文字列
S の長さ∣S∣ は、2 ≤ ∣S∣ ≤ 10 を満たす
1 ≤ a < b ≤ ∣S∣
a,b は整数
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    int a, b;
    cin >> s >> a >> b;

    swap(s[a-1], s[b-1]);

    cout << s << endl;

    return 0;
}
