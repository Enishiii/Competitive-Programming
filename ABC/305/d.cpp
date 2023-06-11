/* 問題文
高橋くんは睡眠記録をつけています。 睡眠記録は奇数長の数列 A=(A1(=0),A2,…,AN) で表され、奇数番目は起床時刻を、偶数番目は就寝時刻を表しています。 より厳密には、睡眠記録をつけている間に高橋くんは次のような睡眠をとりました。
・すべての 1≤i≤N−1/2 を満たす整数 i について、睡眠記録をつけ始めてから A2i  分後ちょうどに寝て、A2i+1  分後ちょうどに起きた。
・それ以外の時間に寝ることも起きることもなかった。
次の Q 個の質問に答えてください。
i 番目の質問では、0≤li ≤ri ≤AN を満たす整数の組(li ,ri) が与えられます。
睡眠記録をつけ始めてから li 分後ちょうどから ri 分後ちょうどまでの ri−li 分のうち、高橋くんが寝ていたのは何分間ですか？

制約
3≤N<2×10^5
N は奇数
0=A1 <A2 <⋯<AN ≤10^9
1≤Q≤2×10^5
0≤li≤ri ≤AN (1≤i≤Q)
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 睡眠記録を入力
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 累積睡眠時間を計算
    vector<int> sleep(n);
    for (int i = 1; i < n; ++i) {
        sleep[i] = sleep[i-1];
        if (i % 2 == 0) sleep[i] += a[i] - a[i-1];
    }

    int q;
    cin >> q;

    // 与えられた時間までに高橋くんが寝ていた時間を計算するラムダ関数
    auto calc_sleep_time{[&a, &sleep](auto x) -> unsigned {
        const auto j = upper_bound(begin(a)+1, end(a), x) - begin(a) - 1;
        return sleep[j] + (sleep[j+1] - sleep[j]) / (a[j+1] - a[j]) * (x - a[j]);
    }};

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << calc_sleep_time(r) - calc_sleep_time(l) << "\n";
    }

    return 0;
}
