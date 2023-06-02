/* 問題文
x 軸上にN 個の観光スポットがあり、1,2,...,N の番号がついています。 観光スポットi は座標Ai の点にあります。 また、x 軸上を座標a の点から座標b の点まで移動するには∣a−b∣ 円かかります。
あなたはx 軸上を旅行する計画を立てました。 計画では、最初に座標0 の点を出発し、N 個の観光スポットを番号順に訪れ、最後に座標0 の点に戻ってくることになっています。
ところが、旅行の直前に急用が入り、N 個すべての観光スポットを訪れる時間的余裕がなくなってしまいました。 そこで、あるi を選び、観光スポット
i を訪れるのを取りやめることにしました。 それ以外の観光スポットは予定通り番号順に訪れます。 また、最初に座標0 の点を出発し、最後に座標
0 の点に戻ってくることについても、予定に変更はありません。
i=1,2,...,N それぞれについて、観光スポットi を訪れるのを取りやめたときの、旅行中の移動にかかる金額の総和を求めてください。

制約
2 ≤ N ≤ 10^5
−5000 ≤ Ai ≤ 5000 (1≤i≤N)
入力値はすべて整数である。 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int total_diff = 0;
    int previous_val = 0;

    // 隣り合う要素との絶対値の差の合計を求める
    // 0からスタートして、0に戻ることに注意
    for (int i = 0; i < n; ++i) {
        total_diff += abs(previous_val - a[i]);
        previous_val = a[i];
    }
    total_diff += abs(previous_val);

    // 各a[i]について、隣り合う要素との差を合計から引く（a[i]を通らずにスキップするのと同義）
    // 新しく、前と後ろの要素の差の絶対値を追加する
    for (int i = 0; i < n; ++i) {
        int prev = (i > 0) ? a[i-1] : 0;
        int current = a[i];
        int next = (i < n-1) ? a[i+1] : 0;

        int ans = total_diff;
        ans -= abs(prev - current);
        ans -= abs(current - next);
        ans += abs(prev - next);

        cout << ans << '\n';
    }

    return 0;
}
