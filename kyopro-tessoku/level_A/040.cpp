/* 問題文
机の上にN 本の棒が置かれています。 左からi 番目の棒（棒i とする）の長さはAi メートルです。
3 つの異なる棒を選んで正三角形を作る方法は何通りありますか。

制約
3 ≤ N ≤ 2×10^5
1 ≤ Ai ≤ 100
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 1〜100までの個数を数える
    vector<int> cnt(101);
    for (int i = 1; i <= 100; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;

    // n個から３つ選ぶ方法はnC3通り。
    // これは、n * (n-1) * (n-2) / 6で求められる
    long long ans = 0;
    for (int i = 1; i <= 100; ++i) {
        ans += (long long)cnt[i] * (cnt[i]-1) * (cnt[i]-2) / 6;
    }
    cout << ans << endl;

    return 0;
}
