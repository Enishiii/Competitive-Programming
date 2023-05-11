/* 問題文
あるリゾートホテルには，1 号室からN 号室までのN 個の部屋があります．
i 号室はAi 人部屋です．このホテルではD 日間にわたって工事が行われることになっており，d 日目はLd 号室からRd 号室までの範囲を使うことができません．d=1,2,⋯D について，d 日目に使える中で最も大きい部屋は何人部屋であるか，出力するプログラムを作成してください．

制約
3 ≤ N ≤ 100000
1 ≤ D ≤ 100000
1 ≤ Ai ≤ 100
2 ≤ Li ≤ Ri ≤ N−1
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力を受け取り、前からの最大値を配列に記録する
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) p[i] = a[i];
        else p[i] = max(p[i-1], a[i]);
    }

    // 後ろからの最大値を配列に記録する
    vector<int> q(n);
    for (int i = n-1; i >= 0; --i) {
        if (i == n-1) q[i] = a[i];
        else q[i] = max(q[i+1], a[i]);
    }

    // 前からl-1までの最大値と、後ろからr+1までの最大値を比べて大きい方を出力
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << max(p[l-1], q[r+1]) << endl;
    }

    return 0;
}
