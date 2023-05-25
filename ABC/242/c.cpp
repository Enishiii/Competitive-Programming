/* 問題文
整数N が与えられるので、以下の条件を全て満たす整数X の個数を
998244353 で割った余りを求めてください。
    ・N 桁の正整数である。
    ・X の各桁を上の位から順にX1, X2, …, XN とする。このとき以下の条件を全て満たす。
        ・全ての整数1≤i≤N に対して、1≤Xi≤9
        ・全ての整数1≤i≤N−1 に対して、∣Xi−Xi+1∣≤1

制約
N は整数
2≤N≤10^6 */

#include <iostream>
#include <vector>
using namespace std;

void add(int &x, int y, int mod) {
    x += y;
    x %= mod;
}

int main() {
    int n;
    cin >> n;

    const int MOD = 998244353;

    // メモ化再帰の動的計画法で解く
    // dp[n][k] := n桁目がk(1~9)になる数
    vector<vector<int>> dp(n+1, vector<int>(10, 0));

    for (int d = 1; d <= 9; ++d) dp[1][d] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int d = 1; d <= 9; ++d) {
            if (d > 1) {
                add(dp[i][d], dp[i-1][d-1], MOD);
            }
            add(dp[i][d], dp[i-1][d], MOD);
            if (d < 9) {
                add(dp[i][d], dp[i-1][d+1], MOD);
            }
        }
    }

    int ans = 0;
    for (int d = 1; d <= 9; ++d) add(ans, dp[n][d], MOD);
    cout << ans << endl;

    return 0;
}
