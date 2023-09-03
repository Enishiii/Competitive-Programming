/* 問題文
高橋くんは満月が好きです。
今日を1 日目とすると、今日以降で満月を見られる最初の日は
M 日目です。以後はP 日ごと、つまりM+P 日目、M+2P 日目、… に満月を見られます。
1 日目からN 日目まで（両端を含む）の中で、高橋くんが満月を見られる日の数を求めてください。

制約
1 ≤ N ≤ 2×10^5
1 ≤ M ≤ P ≤ 2×10^5
入力される数値は全て整数 */

#include <iostream>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;
    while(m <= n) {
        ans++;
        m += p;
    }
    cout << ans << endl;

    return 0;
}
