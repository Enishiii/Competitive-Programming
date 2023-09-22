/*
問題文
人1 、人2 、… 、人N のN 人の人がルーレットの賭けに参加しました。 このルーレットの出目は、0 から36 までの37 個の整数のうちいずれかです。
i=1,2,…,N について、人i は37 個の目のうちCi 個の目Ai,1, Ai,2, …, Ai,Ci に賭けました。
ルーレットが回され、出目はX でした。X に賭けた人たちのうち、賭けた目の個数が最も少ない人たちの番号を昇順にすべて出力してください。
より形式的には、1 以上N 以下の整数i であって、下記の2 つの条件をともに満たすものを昇順にすべて出力してください。
    ・人i はX に賭けている。
    ・任意のj=1,2,…,N について「人j がX に賭けているならば、Ci ≤ Cj 」が成り立つ。
出力するべき番号が1 つも無い場合もあることに注意してください。

制約
1 ≤ N ≤ 100
1 ≤ Ci ≤ 37
0 ≤ Ai,j ≤ 36
任意のi=1,2,…,N について、Ai,1, Ai,2, …, Ai,Ci はすべて異なる。
0 ≤ X ≤ 36
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>());
    vector<int> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        a[i].resize(c[i]);
        for (int j = 0; j < c[i]; ++j) cin >> a[i][j];
    }

    int x;
    cin >> x;

    vector<int> winner;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < c[i]; ++j) {
            if (a[i][j] == x) {
                winner.push_back(i);
            }
        }
    }

    int cmin = 37;
    for (auto i : winner) cmin = min(cmin, c[i]);

    vector<int> ans;
    for (auto i : winner) if (c[i] == cmin) ans.push_back(i+1);

    cout << ans.size() << endl;
    for (auto b : ans) cout << b << " ";
    cout << endl;

    return 0;
}
