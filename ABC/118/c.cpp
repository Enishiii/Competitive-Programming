/* 問題文
N 体のモンスターが居て、それぞれ 1,2,...,N と番号付けられています。
はじめ、モンスター i の体力は Ai です。
以降、体力が1 以上のモンスターを生きているモンスターと呼びます。
生きているモンスターが 1 体になるまで以下を繰り返します。
・ランダムに 1 体の生きているモンスターがランダムに別の生きているモンスターに攻撃します。
・その結果、攻撃されたモンスターの体力を攻撃したモンスターの体力と同じ値だけ減らします。
最後に生き残ったモンスターの最終的な体力の最小値を求めてください。

制約
入力は全て整数である。
2≤N≤10^5
1≤Ai ≤10^9*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// aとbの最大公約数を計算する関数
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    // 入力
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = a[0]; // 最初のモンスターの体力を初期値とする

    // 全てのモンスターの体力に対して最大公約数を計算
    for (int i = 1; i < n; ++i) {
        ans = gcd(ans, a[i]);
    }

    cout << ans << endl;

    return 0;
}
