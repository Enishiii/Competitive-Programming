/* 問題文
N 台のプリンターがあり、1 からN までの番号が付けられています。プリンターi はAi 秒ごとにチラシを1 枚印刷します。すなわち、スイッチを入れてからAi 秒後、2Ai 秒後、3Ai 秒後･･･ に印刷します。すべてのプリンターのスイッチを同時に入れたとき、K 枚目のチラシが印刷されるのは何秒後でしょうか。

制約
1 ≤ N ≤ 100000
1 ≤ K ≤ 10^9
1 ≤ Ai ≤ 10^9
答えは10^9 を超えない
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

// x秒後の合計印刷枚数sumがk以上かどうかを判定
bool check(int x, int k, vector<int> a) {
    long long sum = 0;
    for (auto s : a) sum += x / s;
    if (sum >= k) return true;
    else return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // 答えが10^9までなので、その範囲を二分探索して合計印刷枚数が初めてk以上になる秒数を見つける
    const int Max = 1'000'000'000;
    int left = 0, right = Max;
    while(left < right) {
        int mid = (left+right) / 2;
        if (check(mid, k, a)) right = mid;
        else left = mid + 1;
    }
    cout << left << endl; // left == rightになっている

    return 0;
}
