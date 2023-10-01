/*
問題文
英小文字からなる文字列S,T が与えられます。S の長さはN、T の長さは
M です。(N≤M が制約で保証されています)
S がT の 接頭辞 であるとは、T のはじめN 文字からなる文字列が
S と一致することを言います。
S がT の 接尾辞 であるとは、T の後ろN 文字からなる文字列が
S と一致することを言います。
S がT の接頭辞であり、かつ接尾辞でもある場合は0 を、
S がT の接頭辞であるが、接尾辞でない場合は1 を、
S がT の接尾辞であるが、接頭辞でない場合は2 を、
S がT の接頭辞でも接尾辞でもない場合は3 を出力してください。

制約
1≤N≤M≤100
S は英小文字からなる長さ
N の文字列
T は英小文字からなる長さ
M の文字列
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    bool isPrefix = (s == t.substr(0, n));
    bool isSuffix = (s == t.substr(m-n, n));

    if (isPrefix && isSuffix) cout << 0 << endl;
    else if (isPrefix) cout << 1 << endl;
    else if (isSuffix) cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}
