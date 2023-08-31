#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    // 入力
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // +1と-1の操作後で、配列全体の総和は不変であることに注目
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];

    // sum = n * x + rから、全ての操作終了後の配列bを作る
    ll x = sum / n;
    ll r = sum % n;
    vector<ll> b(n, x);
    for (int i = 0; i < r; ++i) {
        b[i]++; // r個の要素を+1することで、配列全体の総和をaと等しくする
    }

    // 先頭からの各要素の差が最も小さくなるよう、2つの配列をともに昇順でソート
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;

    // 1回の操作で+1と-1で合わせて2の差がなくなっていく
    // 差の合計値を2で割った値が最小の操作回数になる
    for (int i = 0; i < n; ++i) ans += abs(a[i] - b[i]);
    cout << ans / 2 << endl;

    return 0;
}
