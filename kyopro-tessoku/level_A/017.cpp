/* 問題文
あるダンジョンにはN 個の部屋があり、1 からN までの番号が付けられています。このダンジョンは一方通行であり、通路を介して1 つ先または
2 つ先の部屋に移動することができます。各通路における移動時間は以下の通りです。
・部屋i−1 から部屋i に向かう通路を通るのにAi 分 (2≤i≤N) かかる。
・部屋i−2 から部屋i に向かう通路を通るのにBi 分 (3≤i≤N) かかる。
太郎君が部屋1 から部屋N へ最短時間で移動する方法を1 つ出力するプログラムを作成してください。

制約
3 ≤ N ≤ 100000
1 ≤ Ai ≤ 100 (2 ≤ i ≤ N)
1 ≤ Bi ≤ 100 (3 ≤ i ≤ N)
入力される値はすべて整数である。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    for (int i = 2; i <= n; ++i) cin >> a[i];
    for (int i = 3; i <= n; ++i) cin >> b[i];

    // 動的計画法で最短時間を求める
    vector<int> dp(n+1);
    dp[1] = 0;
    dp[2] = a[2];
    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i-1] + a[i], dp[i-2] + b[i]);
    }

    vector<int> ans; // 最短経路を記録する配列
    int place = n; // ゴール地点からスタートまで遡っていく
    while(1) {
        ans.push_back(place); // 通る地点を記録していく
        if (place == 1) break; // スタートに着いたら終了

        // aを通る方が短いなら、aを通って１つ遡る。そうでないなら、bを通って2つ遡る
        if (dp[place] == dp[place-1] + a[place]) place--;
        else place -= 2;
    }

    // ゴールから記録しているので、スタートから始まる配列にする
    reverse(ans.begin(), ans.end());

    // 出力
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
