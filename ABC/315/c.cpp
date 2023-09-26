/*
問題文
N カップのアイスクリームがあります。
i カップ目の味はFi、美味しさはSi(Siは偶数) です。
あなたは、N 個のカップの中から2 つを選んで食べることにしました。
このときの満足度は次のように定義されます。
    ・食べたアイスクリームの美味しさをs,t (但し、s ≥ t) とする。
        ・2 つのカップの味が異なるなら、満足度はs + t である。
        ・そうでないなら、満足度はs + t/2 である。
満足度として達成可能な最大値を求めてください。

制約
入力は全て整数
2 ≤ N ≤ 3×10^5
1 ≤ Fi ≤ N
2 ≤ Si ≤ 10^9
Si は偶数
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    // 入力を受け取り、最大値とそのインデックスを保持する
    int n;
    cin >> n;

    vector<ll> f(n), s(n);
    ll mx = 0; // 美味しさの最大値
    int mxIdx = 0; // 最大値のインデックス

    for (int i = 0; i < n; ++i) {
        cin >> f[i] >> s[i];
        if (mx < s[i]) {
            mx = s[i];
            mxIdx = i;
        }
    }

    // もう１つ食べるアイスとしてn-1カップを全て試し、最大の満足度を探す
    ll ans = 0; // 最大で10^9+10^9なので、long longを使う
    for (int i = 0; i < n; ++i) {
        if (i != mxIdx) {
            ll cur = mx + (f[i] == f[mxIdx] ? (s[i] / 2) : s[i]); // 味が同じならs[i]/2を足し、そうでないならs[i]を足す
            ans = max(ans, cur);
        }
    }

    cout << ans << endl;

    return 0;
}
