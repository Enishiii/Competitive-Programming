/* 問題文
N1 +N2 頂点M 辺の無向グラフがあります。
i=1,2,…,M に対し、i 番目の辺は頂点 ai と頂点bi を結びます。
また、以下を満たすことが保障されます。
・1≤u,v≤N1  を満たす整数u,v に対し、頂点u と頂点v は連結
・N +1≤u,v≤N1+N2を満たす整数 u,v に対し、頂点u と頂点v は連結
・頂点 1 と頂点N1+N2は非連結
次の操作をちょうど 1 回行います。
1≤u≤N1を満たす整数 u とN1+1≤v≤N1+N2 を満たす整数 v を選び、頂点u と頂点 v を結ぶ辺を追加する操作後のグラフにおいて、頂点 1 と頂点 N1+N2は必ず連結であることが示せます。そこで、頂点1 と頂点 N1+N2を結ぶ経路の長さ(辺の本数)の最小値を d とします。
操作で追加する辺を適切に選んだ時にありえる d の最大値を求めてください。

制約
1≤N1 ,N2 ≤1.5×10^5
0≤M≤3×10^5
1≤ai ≤bi ≤N1 +N2
​i !=j ならば(ai,bi) != (aj,bj)
1≤u,v≤N1 を満たす整数u,v に対し、頂点u と頂点v は連結
N1+1≤u,v≤N1 +N2 を満たす整数 u,v に対し、頂点 u と頂点 v は連結
頂点 1 と頂点N1+N2 は非連結
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 開始頂点から各頂点への最大距離を計算する関数
int calcMaxDist(vector<vector<int>> e, int s) {
    int n = e.size();
    vector<int> dist(n, -1);

    dist[s] = 0; // スタート地点の距離は0
    queue<int> q;
    q.push(s);

    // キューがからになるまで探索を行う（幅優先探索BFS）
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < e[x].size(); ++i) {
            int y = e[x][i];
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }

    // 全ての頂点への距離の中で最大のものを返す
    return *max_element(dist.begin(), dist.end());
}

int main() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    vector<vector<int>> graph(n1+n2);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--; // 0-indexedに変換

        // 無向グラフなので両方向に辺を追加
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    /* (u, v)に対し操作をした後のグラフは以下のようになる
    ・頂点1から頂点uへ最短経路を通る
    ・頂点u, vを結ぶ辺（追加した辺）を通る
    ・頂点vから頂点n1 + n2へ最短経路を通る
    */

    // よって、頂点0からの最大距離と頂点n1+n2-1からの最大距離を求め、それらの和+1を出力
    cout << calcMaxDist(graph, 0) + calcMaxDist(graph, n1+n2-1) + 1 << endl;

    return 0;
}
