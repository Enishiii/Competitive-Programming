/* 問題文
長さN の数列a=(a1, a2, ..., aN) があります。 各ai は正の整数です。
すぬけ君の目標は、a の要素を自由に並べ替え、次の条件が成り立つようにすることです。
    ・各1≤i≤N−1 について、ai とai+1 の積は4 の倍数である。
すぬけ君が目標を達成できるか判定してください。

制約
2 ≤ N ≤ 10^5
ai は整数である。
1 ≤ ai ≤ 10^9 */

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int odd = 0, even_not_four = 0, multiple_of_four = 0;

    // 各種数のカウントを行う
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a % 4 == 0) multiple_of_four++;
        else if (a % 2 == 0) even_not_four++;
        else odd++;
    }

    // 結果を表示
    // 14141->Yes
    // 1414142222->Yes 2は一箇所にまとめることで、奇数1つと等価になる
    if (even_not_four == 0) {
        if (odd <= multiple_of_four + 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        if (odd <= multiple_of_four) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
