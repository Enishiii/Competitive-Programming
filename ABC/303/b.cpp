/* 問題文
1,2,…,N と番号づけられたN 人がM 回、一列に並んで集合写真を撮りました。i 番目の撮影で左からj 番目に並んだ人の番号はai,jです。
ある二人組はM 回の撮影で一度も連続して並ばなかった場合、不仲である可能性があります。　　
不仲である可能性がある二人組の個数を求めてください。なお、人x と人
y からなる二人組と人y と人x からなる二人組は区別しません。

制約
2 ≤ N ≤ 50
1 ≤ M ≤ 50
1 ≤ ai,j ≤ N
ai,1, …, ai,N には1, …, N が1 回ずつ現れる
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

// グラフで隣り合ったペアを管理する

int main() {
    // 入力
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j]; // 0-indexedにする
        }
    }

    // グラフの初期化
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                g[i][j] = true;
        }
    }

    // それぞれの写真で隣り合っているペアにエッジを追加
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            int u = a[i][j], v = a[i][j + 1];
            g[u][v] = g[v][u] = true;
        }
    }

    // 不仲ペアの数をカウント
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!g[i][j])
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
