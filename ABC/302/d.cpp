/* 問題文
高橋君は青木君とすぬけ君に1 つずつ贈り物を送ることにしました。
青木君への贈り物の候補はN 個あり、 それぞれの価値はA1,A2,…,AN です。
すぬけ君への贈り物の候補はM 個あり、 それぞれの価値はB1,B2,…,BM です。
高橋君は2 人への贈り物の価値の差がD 以下になるようにしたいと考えています。
条件をみたすように贈り物を選ぶことが可能か判定し、可能な場合はそのような選び方における贈り物の価値の和の最大値を求めてください。

制約
1 ≤ N,M ≤ 2×10^5
1 ≤ Ai,Bi ≤ 10^18
0 ≤ D ≤ 10^18
入力はすべて整数

出力
高橋君が条件をみたすように贈り物を選ぶことができる場合、 条件をみたし、かつ価値の和が最大になるように贈り物を選んだ時の価値の和を出力せよ。 高橋君が条件をみたすように選ぶことができない場合、
−1 を出力せよ。 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    // 入力
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    // 二分探索を使いたいのでソートしておく
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll max_sum = -1;
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(b.begin(), b.end(), a[i] + d); // a[i]+dより大きい最初の要素の位置を特定
        if (it != b.begin()) { // 上記の要素の位置が見つかった場合
            ll b = *(--it); // １引いた位置の要素の値を取得
            if (b >= a[i] - d) max_sum = max(max_sum, a[i] + b); // 条件を満たすなら、和の最大値をとる
        }
    }
    cout << max_sum << endl;

    return 0;
}
