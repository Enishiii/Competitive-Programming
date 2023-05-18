/* 問題文
長さN の整数からなる数列A=(A1, …, AN), B=(B1, …, BN) が与えられます。
以下の条件を全て満たす長さN の数列X=(X1, …, XN) が存在するかを判定してください。
    ・すべてのi(1≤i≤N) について、Xi = Ai またはXi = Bi
    ・すべてのi(1≤i≤N−1) について、∣Xi − Xi+1∣ ≤ K

制約
1 ≤ N ≤ 2×10^5
0 ≤ K ≤ 10^9
1 ≤ Ai, Bi ≤ 10^9
入力は全て整数である */

#include <iostream>
#include <vector>
using namespace std;

// 隣り合う要素の差の絶対値がk以下か判定(2つ目の条件)
bool checkDifference(int previous, int current, int k) {
    return abs(previous - current) <= k;
}

int main() {
    // 入力
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // 動的計画法で解く。dpとepを用意。
    // dp[i] := (X1, X2, ..., Xi)まで考慮した時、Xi = Aiとしてよいか
    // ep[i] := (X1, X2, ..., Xi)まで考慮した時、Xi = Biとしてよいか
    vector<bool> dp(n, false), ep(n, false);

    // 初期値をセット
    dp[0] = ep[0] = true;

    // 条件を満たすものをtrueにしていく
    for (int i = 1; i < n; ++i) {
        if (dp[i-1]) {
            if (checkDifference(a[i-1], a[i], k)) dp[i] = true;
            if (checkDifference(a[i-1], b[i], k)) ep[i] = true;
        }
        if (ep[i-1]) {
            if (checkDifference(b[i-1], a[i], k)) dp[i] = true;
            if (checkDifference(b[i-1], b[i], k)) ep[i] = true;
        }
    }

    if (dp[n-1] || ep[n-1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
