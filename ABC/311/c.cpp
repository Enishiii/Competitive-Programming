/* 問題文
N 頂点N 辺の有向グラフがあります。
i 番目の辺は頂点i から 頂点Ai に伸びます。 (i != Ai であることは制約より保証されます)
同一頂点を複数回含まない有向閉路をひとつ求めてください。
なお、この問題の制約下で答えが存在することが示せます。

注釈
この問題では、有向閉路とは以下の条件を全て満たす頂点の列B=(B1, B2, …, BM) であるとします。
    ・M >= 2
    ・Bi からBi+1 に辺が伸びている。 (1≤i≤M−1)
    ・BM からB1 に辺が伸びている。
    ・i != j ならばBi != Bj
​
制約
入力は全て整数
2≤N≤2×10^5
1≤Ai≤N
Ai != i */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int v, vector<vector<int>>&edge, vector<int>& visited, vector<int>& path, int& cycleStart, int& cycleEnd) {
    visited[v] = 1; // 現在の頂点を訪問済みにする

    path.push_back(v);

    // 現在の頂点から繋がっている頂点を辿る
    for (auto u : edge[v]) {
        // まだ訪問していないなら、再帰的にDFS
        if (visited[u] == 0) {
            if (dfs(u, edge, visited, path, cycleStart, cycleEnd)) return true;
        } else { // すでに訪問済みの頂点に再度たどり着いた場合、閉路を見つけたと判定
            // 閉路の始点と終点を記録し、trueを返す
            cycleStart = u;
            cycleEnd = v;
            return true;
        }
    }

    visited[v] = 2; // 全ての子頂点を調べ終わったことを記録
    path.pop_back(); // 現在の頂点をパスから除外
    return false; // 閉路は見つからなかったので、falseを返す（本問では必ず見つかるはず）
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edge(n+1, vector<int>());
    vector<int> path;
    vector<int> visited(n+1, 0);
    int cycleStart, cycleEnd;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        edge[i].push_back(a);
    }

    // 全ての頂点についてDFSを実行
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i, edge, visited, path, cycleStart, cycleEnd)) break;
    }

    // 閉路の始点と終点がパス上のどこに位置しているかを見つける
    auto it_start = find(path.begin(), path.end(), cycleStart);
    auto it_end = find(path.begin(), path.end(), cycleEnd);

    // 閉路の部分だけを取り出す
    vector<int> cycle(it_start, it_end+1);

    cout << cycle.size() << endl;
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
