/* 問題文
長さ N の整数列 A=(A1,A2,…,AN) が与えられます。
長さM のA の連続部分列 B=(B1,B2,…,BM) に対する、i=1∑M i×Bi の最大値を求めてください。

注記
数列の連続部分列とは、数列の先頭から 0 個以上、末尾から 0 個以上の要素を削除して得られる列のことをいいます。
例えば(2,3) や (1,2,3) は (1,2,3,4) の連続部分列ですが、(1,3) や (3,2,1) は (1,2,3,4) の連続部分列ではありません。

制約
1≤M≤N≤2×10^5
−2×10^5≤Ai ≤2×10^5
 入力は全て整数。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Long = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<Long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    Long s = 0, t = 0;

    // 最初の部分列の加重和を計算
    for (int i = 0; i < m; ++i) s += a[i]*(i+1);

    // 最初の部分列の和を計算
    for (int i = 0; i < m; ++i) t += a[i];

    Long ans = s;
    for (int i = 0; i < n-m; ++i) {
        Long ns = s - t + a[i+m]*m; // 新しい部分列の加重和
        Long nt = t - a[i] + a[i+m]; // 新しい部分列の和
        s = ns, t = nt; // 値を更新
        ans = max(ans, s); // これまでに見つかった最大の加重和を保持する
    }
    cout << ans << endl;

    return 0;
}
