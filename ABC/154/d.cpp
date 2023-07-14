/* 問題文
N 個のサイコロが左から右に一列に並べてあります。左から i 番目のサイコロは 1 から piまでの pi 種類の目がそれぞれ等確率で出ます。
隣接する K 個のサイコロを選んでそれぞれ独立に振ったとき、出る目の合計の期待値の最大値を求めてください。

制約
1≤K≤N≤200000
1≤pi≤1000
入力で与えられる値は全て整数 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // 期待値を前もって求める
    vector<double> e(n);
    for (int i = 0; i < n; ++i) e[i] = (p[i]+1) / 2; // e = (1/p) * [1 + 2 + ... + p] = (1/p) * p*(p+1)/2 = (p+1)/2

    // 累積和を求めておく
    vector<double> s(n+1, 0);
    for (int i = 0; i < n; ++i) s[i+1] = s[i] + e[i];

    double maxE = 0;
    for (int i = 0; i <= n-k; ++i) {
        maxE = max(maxE, s[i+k] - s[i]);
    }

    cout << setprecision(10) << maxE << endl;

    return 0;
}
