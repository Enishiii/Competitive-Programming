/* 問題文
宝箱にはN 個の品物が入っており、それぞれ1 からN までの番号が付けられています。
品物i の重さはw[i] であり、価値はv[i] です。
太郎君は、いくつかの品物を選んで持ち帰りたいと考えています。
しかし、彼のナップザックには容量制限があるので、重さの合計が
W 以下になるようにする必要があります。
価値の合計としてあり得る最大の値はいくつですか。

制約
1 ≤ N ≤ 100
1 ≤ W ≤ 100000
1 ≤ w[i] ≤ W
1 ≤ v[i] ≤ 10^9
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力を受け取る
    int N, W;
    cin >> N >> W;
    vector<int> w(N+1);
    vector<long long> v(N+1);
    for (int i = 1; i <= N; ++i) cin >> w[i] >> v[i];

    // dp[i][j]: 品物1, 2, ...iの中から、重さの合計がjとなるよう選び、その時の合計価値として最大のものを記録していく
    long long dp[N+1][W+1];
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = -1; // ありえない値で初期化することでこの後の場合分けを減らす
        }
    }

    // 動的計画法
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    // 最大値を見つけて出力
    long long ans = 0;
    for (int i = 0; i <= W; ++i) ans = max(ans, dp[N][i]);
    cout << ans << endl;

    return 0;
}
