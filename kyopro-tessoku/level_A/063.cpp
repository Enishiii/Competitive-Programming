/* 問題文
N 頂点M 辺の無向グラフが与えられます。各頂点には1 からN までの番号が付けられており、i 番目の辺は頂点Ai と頂点Bi を結んでいます。
1 以上N 以下の全ての整数k について、以下の問いに答えてください。

頂点1 から頂点k まで、辺を何本かたどって移動することを考えるとき、たどるべき辺の本数の最小値を出力せよ。ただし、移動不可能な場合は−1 を出力せよ。

制約
入力はすべて整数
1 ≤ N ≤ 10^5
0 ≤ M ≤ min(10^5,N*(N−1)/2)
1 ≤ Ai < Bi ≤ N
グラフに多重辺や自己ループは存在しない */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // 入力を受け取って、グラフを表す隣接行列を作る
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n); // 各頂点の最短距離を保持する配列
    queue<int> q;

    for (int i = 0; i < n; ++i) dist[i] = -1; // -1で初期化
    q.push(0);
    dist[0] = 0; //　最初の頂点

    // 幅優先探索で各頂点までの最短距離を求める
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        for (int next : g[pos]) {
            if (dist[next] == -1) {
                dist[next] = dist[pos] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << dist[i] << endl;

    return 0;
}
