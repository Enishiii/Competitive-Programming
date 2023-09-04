/* 問題文
高橋君は N 日間の鉄道旅行を計画しています。
高橋君はそれぞれの日について、運賃の通常料金を払うか、1 日周遊パスを 1 枚使用するか選ぶことができます。
ここで、1≤i≤N について、i 日目の旅行にかかる運賃の通常料金は Fi 円です。
一方、1 日周遊パスはD 枚セットでP 円で発売されており、何セットでも購入することが可能ですが、D 枚単位でしか購入することができません。
また、購入したパスは 1 枚ずつ好きな日に使うことができ、旅行が終了した時点で余っていても構いません。
N 日間の旅行でかかる金額、すなわち 1 日周遊パスの購入にかかった代金と、1 日周遊パスを利用しなかった日における運賃の通常料金の合計金額の和としてあり得る最小値を求めてください。

制約
1 ≤ N ≤ 2×10^5
1 ≤ D ≤ 2×10^5
1 ≤ P ≤ 10^9
1 ≤ Fi ≤ 10^9
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n, d, p;
    cin >> n >> d >> p;
    vector<int> fares(n);
    for (int i = 0; i < n; ++i) cin >> fares[i];

    sort(fares.begin(), fares.end());

    vector<ll> cumulativeSum(n+1);
    for (int i = 0; i < n; ++i) {
        cumulativeSum[i+1] = cumulativeSum[i] + fares[i];
    }

    ll minCost = cumulativeSum[n];
    for (int i = 0; i < 1e9; ++i) { // i: パスを購入するセット数
        int daysToRegularFare = max(0, n - i * d);

        // パスのセット数*d日分の値段を除去した、通常価格の合計
        ll costWithoutPass = cumulativeSum[daysToRegularFare];

        // 通常価格の合計に、パスの値段p*セット数iを足して合計金額を出す
        ll totalCost = costWithoutPass + (ll)p * i;

        minCost = min(minCost, totalCost);

        if (daysToRegularFare == 0) break;
    }

    cout << minCost << endl;

    return 0;
}

/*
別解
int main() {
    int n, d, p;
    cin >> n >> d >> p;
    vector<int> f(n);
    for (int i = 0; i < n; ++i) cin >> f[i];
    sort(f.begin(), f.end());

    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += f[i];
    while(f.size()) {
        ll s = 0;
        int sz = min<int>(d, f.size());
        for (int i = 0; i < sz; ++i) {
            s += f.back();
            f.pop_back();
        }
        if (s < p) break;
        ans -= s - p;
    }
    cout << ans << endl;

    return 0;
}
*/
