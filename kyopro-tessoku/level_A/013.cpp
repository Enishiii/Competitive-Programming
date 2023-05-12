/* 問題文
N 個の整数が黒板に書かれています。書かれた整数は小さい順にA1,A
2,⋯,AN です。異なる2 つの整数のペアを選ぶ方法は全部でN(N−1)/2 通りありますが、その中で差がK 以下であるような選び方は何通りありますか。

制約
1 ≤ N ≤ 100000
1 ≤ K ≤ 10^9
1 ≤ A1 < A2 < ⋯ < AN ≤ 10^9
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // しゃくとり法
    vector<int> r(n);
    for (int i = 0; i < n-1; ++i) {
        // スタート地点を決める
        if (i == 0) r[i] = 0;
        else r[i] = r[i-1];

        // ギリギリまで増やしていく
        while(r[i] < n-1 && a[r[i]+1]-a[i] <= k) {
            r[i]++;
        }
    }

    // 出力
    long long ans = 0;
    for (int i = 0; i < n-1; ++i) ans += (r[i] - i);
    cout << ans << endl;

    return 0;
}
