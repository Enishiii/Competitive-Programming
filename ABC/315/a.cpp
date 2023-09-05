/*
問題文
英小文字からなる文字列S が与えられます。
S から a, e, i, o, u をすべて取り除いて得られる文字列を出力してください。
なお、S は a, e, i, o, u 以外の文字を一つ以上含みます。

制約
S は英小文字からなる長さ1 以上100 以下の文字列
S は a, e, i, o, u 以外の文字を一つ以上含む
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result;
    for (char ch : s) {
        if (string("aeiou").find(ch) == string::npos) {
            result += ch;
        }
    }
    cout << result << endl;

    return 0;
}
