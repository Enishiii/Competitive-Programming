/* 問題文
N 個の石が積まれた山があり、2 人のプレイヤーが交互に石を取り合います。
各プレイヤーは1 回のターンで、以下のいずれかの操作をすることができます。
・山からA 個の石を取り除く。
・山からB 個の石を取り除く。
先に石を取り除けなくなった方が負けです。両者が最善を尽くしたとき、先手と後手どちらが勝ちますか。

制約
N, A, B は整数
2 ≤ N ≤ 100000
1 ≤ A < B ≤ N */

#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    // dp[x] = trueのとき勝つ状態、falseのとき負ける状態
    bool dp[n+1];
    for (int i = 0; i <= n; ++i) {
        // 相手のターンを負ける状態にできるか判断
        if (i >= a && dp[i-a] == false) dp[i] = true;
        else if (i >= b && dp[i-b] == false) dp[i] = true;
        // できないなら自分が負け
        else dp[i] = false;
    }

    if (dp[n]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}
