/* 問題文
高橋くんと青木くんがN 回の試合を行いました。 これらの試合の結果を表す長さN の文字列S が与えられます。i 回目の試合の勝者は、S のi 文字目が T ならば高橋くん、A ならば青木くんです。
高橋くんと青木くんのうち、勝った試合の数が多い方を総合勝者とします。 ただし、勝った試合の数が同じである場合は、先にその勝ち数に達した者を総合勝者とします。 高橋くんと青木くんのどちらが総合勝者であるか求めてください。

制約
1 ≤ N ≤ 100
N は整数
S は T および A からなる長さ
N の文字列 */

#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // お互いの勝ち数をカウント
    int t = 0, a = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'T') t++;
        else a++;
    }

    // 数が違うなら大きい方が勝ち。そうじゃないなら、最後に勝者になったのと違う方（同点なら先にその勝ち数を稼いだ方）を出力
    if (t > a) cout << "T" << endl;
    else if (t < a) cout << "A" << endl;
    else {
        if (s.back() == 'T') cout << "A" << endl;
        else cout << "T" << endl;
    }

    return 0;
}
