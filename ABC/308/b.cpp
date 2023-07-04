/* 問題文
高橋くんは回転寿司でN 皿の料理を食べました。i 皿目の色は文字列Ci​ で表されます。
また、料理の価格は皿の色と対応し、i = 1,…,M のそれぞれについて、色が文字列Di​ の皿の料理は一皿Pi​ 円です。また、D1,…,DM​ のいずれとも異なる色の皿の料理は一皿P0​ 円です。
高橋くんが食べた料理の価格の合計を求めてください。

制約
1≤N,M≤100
Ci,Di は英小文字からなる長さ 1 以上 20 以下の文字列
D1,…,DM​ はすべて異なる
1≤Pi≤10000
N,M,Pi​ は整数 */

#include <iostream>
#include <vector>
using namespace std;

// 問題文の通りに素直に実装する

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> c(n), d(m + 1);
    vector<int> p(m + 1);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 1; i <= m; ++i) cin >> d[i];
    for (int i = 0; i <= m; ++i) cin >> p[i];

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        bool matched = false;
        for (int j = 1; j <= m; ++j) {
            if (c[i] == d[j]) {
                sum += p[j];
                matched = true;
            }
        }
        if (!matched) sum += p[0];
    }
    cout << sum << endl;

    return 0;
}
