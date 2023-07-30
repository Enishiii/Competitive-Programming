/* 問題文
英大文字からなる長さ3 の文字列S が与えられます。
S が ACE、BDF、CEG、DFA、EGB、FAC、GBD のいずれかと等しいとき Yes を、そうでないとき No を出力してください。

制約
S は英大文字からなる長さ3 の文字列 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string t = "ACEGBDFAC";
    cout << (t.find(s) == string::npos ? "No" : "Yes") << endl;

    return 0;
}
