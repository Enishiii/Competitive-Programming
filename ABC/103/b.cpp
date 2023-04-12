/* 問題文
英小文字からなる文字列S,T が与えられます。S を回転させてT に一致させられるか判定してください。すなわち、以下の操作を任意の回数繰り返してS をT に一致させられるか判定してください。

操作:
S=S1 S2...S∣S∣のとき、S をS∣S∣ S1 S2...S∣S∣−1に変更する
ここで、∣X∣ は文字列X の長さを表します。

制約
2 ≤ ∣S∣ ≤ 100
∣S∣=∣T∣
S,T は英小文字からなる
*/

#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        s = s.back() + s.substr(0, s.size()-1);
        if (s != t) continue;
        else {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
