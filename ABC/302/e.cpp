/* 問題文
最初N 頂点0 辺の無向グラフがあり、各頂点には1 からN まで番号がついています。Q 個のクエリが与えられるので、順に処理し、各クエリの後における「他のどの頂点とも辺で結ばれていない頂点」の数を出力してください。
i 個目のクエリはqueryi であり、各クエリは次の2 種類いずれかです。
    ・1 u v: 頂点u と頂点v を辺で結ぶ。このクエリが与えられる直前の時点で、頂点u と頂点v は辺で結ばれていない事が保証される。
    ・2 v : 頂点v と他の頂点を結ぶ辺をすべて削除する。（頂点v 自体は削除しない。）

制約
2 ≤ N ≤ 3×10^5
1 ≤ Q ≤ 3×10^5
1 番目の種類のクエリにおいて、1 ≤ u,v ≤ N, u != v
2 番目の種類のクエリにおいて、1 ≤ v ≤ N
1 番目の種類のクエリの直前の時点で、そのクエリのu,v について頂点u と頂点v は辺で結ばれていない。
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// setでグラフを管理することでデータの挿入・削除を高速化する
// あとは問題文の通りに素直に実装する

int main() {
    int n, q;
    cin >> n >> q;

    vector<set<int>> connected(n + 1);
    int isolatedVertices = n;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;

            if (connected[u].empty())
                isolatedVertices--;
            if (connected[v].empty())
                isolatedVertices--;

            connected[u].insert(v);
            connected[v].insert(u);
        }
        else if (type == 2) {
            int v;
            cin >> v;

            if (!connected[v].empty()) {
                for (auto u : connected[v]) {
                    connected[u].erase(v);
                    if (connected[u].empty()) {
                        isolatedVertices++;
                    }
                }

                connected[v].clear();
                isolatedVertices++;
            }
        }

        cout << isolatedVertices << '\n';
    }

    return 0;
}
