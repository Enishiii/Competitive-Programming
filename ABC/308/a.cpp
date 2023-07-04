/* 問題文
8 個の整数S1,S2,…,S8 が与えられます。 以下の3 つの条件が全て満たされるならば Yes を、そうでないならば No を出力してください。
    ・数列(S1,S2,…,S8) は広義単調増加である。すなわち、S1≤S2≤⋯≤S8 である。
    ・S1,S2,…,S8 は全て100 以上675 以下である。
    ・S1,S2,…,S8 は全て25 の倍数である。

制約
0≤Si≤1000
入力は全て整数 */

#include <iostream>
using namespace std;

// 問題文の通りに素直に実装する

int main() {
    int s[8];
    bool ok = true;

    for (int i = 0; i < 8; ++i) {
        cin >> s[i];
        if (s[i] < 100 || s[i] > 675)
            ok = false;
        if (s[i] % 25 != 0)
            ok = false;
        if (i > 0) {
            if (s[i] < s[i - 1])
                ok = false;
        }
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
