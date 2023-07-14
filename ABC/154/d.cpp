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
    int N, K;
    cin >> N >> K;
    vector<double> p(N);
    for (int i = 0; i < N; i++) cin >> p[i];

    // 期待値を求める
    vector<double> E(N);
    for (int i = 0; i < N; i++) E[i] = (p[i] + 1) / 2;

    // 累積和を求める
    vector<double> S(N + 1, 0);
    for (int i = 0; i < N; i++) S[i + 1] = S[i] + E[i];

    // 隣接するK個の期待値の和の最大値を求める
    double maxE = 0;
    for (int i = 0; i <= N - K; i++)
        maxE = max(maxE, S[i + K] - S[i]);

    cout << setprecision(10) << maxE << endl;

    return 0;
}
