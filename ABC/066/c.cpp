/* 問題文
長さn の数列a1,...,an が与えられます。 空の数列b に対して、以下の操作をn 回行うことを考えます。
    ・i 回目には数列のi 番目の要素ai をb の末尾に追加する。
    ・b を逆向きに並び替える。
この操作をしてできる数列b を求めて下さい。

制約
1 ≤ n ≤ 2×10^5
0 ≤ ai ≤ 10^9
n,ai は整数である。 */

#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 素直に実装するなら、reverse一回でO(n)かかるので、結果O(n^2)になって間に合わない->偶奇に着目
    
    // 前後に素早く挿入するためdequeを使う
    deque<int> b;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        // i番目の偶奇とnの偶奇が一致しているなら前
        // そうじゃないなら後ろに挿入
        if (i % 2 == (n-1)%2) b.push_front(a);
        else b.push_back(a);
    }

    // 出力
    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << b[i];
    }
    cout << endl;

    return 0;
}
