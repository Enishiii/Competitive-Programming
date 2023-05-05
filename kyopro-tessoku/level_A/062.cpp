/* 問題文
各頂点に1,2,…,N の番号がついた、N 頂点M 辺の無向グラフが与えられます。
i 番目の辺は頂点Ai と頂点Bi とを結んでいます。
このグラフ全体が連結であるかどうか判定して以下のように出力してください。
・もしグラフ全体が連結であれば、 The graph is connected. と出力する
・そうでなければ、 The graph is not connected. と出力する

制約
入力はすべて整数
1 ≤ N ≤ 10^5
0 ≤ M ≤ min(10^5,N*(N−1)/2)
1 ≤ Ai < Bi ≤ N
グラフに多重辺や自己ループは存在しない
*/

#include <iostream>
#include <vector>
using namespace std;

// 深さ優先探索で連結している頂点を全て訪問
void dfs(int currentPlace, vector<bool> &visited, vector<vector<int>> &g) {
    visited[currentPlace] = true;
    for (int next : g[currentPlace]) {
        if (!visited[next]) dfs(next, visited, g);
    }
}

int main() {
    // 入力を受け取る
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());
    vector<bool> visited(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 深さ優先探索
    dfs(0, visited, g);

    // １つでも訪れていない頂点があれば、連結していないということ
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }
    cout << "The graph is connected." << endl;

    return 0;
}
