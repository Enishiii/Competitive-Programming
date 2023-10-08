/*
問題文
3 文字からなる文字列S が与えられます。S は、1 以上9 以下の整数
a,b と文字 x を、axb のように順につなげて得られます。
a とb の積を求めてください。

制約
S の長さは3
S の1 文字目および3 文字目は1 以上9 以下の整数を表す
S の2 文字目は x
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    cout << (s[0]-'0') * (s[2]-'0') << endl;

    return 0;
}
