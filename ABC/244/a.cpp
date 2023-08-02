/* 問題文
英小文字からなる長さN の文字列S が与えられます。
S の末尾の文字を出力してください。

制約
N は整数
1≤N≤1000
S は英小文字からなる長さN の文字列 */

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    cout << s[n-1] << endl;

    return 0;
}
