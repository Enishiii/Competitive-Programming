/* 問題文
あなたは夏休みの宿題N 個を、毎日 1 つずつ終わらせなければなりません。宿題には1 からN までの番号が付けられており、宿題i の 難易度 は整数
Ai で表されます。
また、夏休みi 日目(1≤i≤N) の気温はBi 度になることが予想されています。「難易度 × 気温」の総和だけ労力がかかるとき、すべての宿題を終わらせるために必要な労力の最小値はいくつですか。

制約
2 ≤ N ≤ 60
1 ≤ Ai ≤ 100
1 ≤ Bi ≤ 45 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // 難易度は小さい順、気温は高い順にソートしてその積をとる
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    int cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += a[i] * b[i];
    }
    cout << cost << endl;

    return 0;
}
