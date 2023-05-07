/* 問題文
頂点数N のグラフに対して、以下の2 種類のクエリを高速に処理してください。
・クエリ1：頂点u と頂点v を双方向に結ぶ辺を追加する。
・クエリ2：頂点u と頂点v は同じ連結成分に属するかを答える。
ただし、最初はグラフに辺が一本もなく、与えられるクエリの数はQ 個であるとします。

制約
2 ≤ N ≤ 100000
1 ≤ Q ≤ 100000
Queryi (1≤i≤Q) はすべてti ui vi の形式
ti ∈{1,2} (1 ≤ i ≤ Q)
1 ≤ ui < vi ≤ N (1 ≤ i ≤ Q)
入力は全て整数 */

#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    public:
    vector<int> par;
    vector<int> size;

    // n頂点のUnion-Find を作成
    UnionFind(int n) {
        par.resize(n, -1);
        size.resize(n, 1);
    }

    // 親を１つずつたどって、頂点x の根を返す（再帰関数でも実装可能だが、読みにくいのでやめた。）
    int root(int x) {
        while(true) {
            if (par[x] == -1) break; // 親が存在しないなら、終了
            x = par[x];
        }
        return x;
    }

    // 要素uとvを統合する
    void unite(int u, int v) {
        int root_u = root(u);
        int root_v = root(v);
        if (root_u == root_v) return; // 根が同じなら、同一グループ

        if (size[root_u] < size[root_v]) swap(root_u, root_v); // 常にroo_uの要素数が大きいようにする
        par[root_v] = root_u; // 要素数が大きい方の根を小さい方の親にすることで、高速化できる
        size[root_u] += size[root_v];
    }

    // 要素uとvが同一のグループか判定する
    bool same(int u, int v) {
        // 根が同じなら、同一グループ
        if (root(u) == root(v)) return true;
        return false;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    for (int i = 0; i < q; ++i) {
        int query, u, v;
        cin >> query >> u >> v;
        u--, v--;

        if (query == 1) {
            uf.unite(u, v);
        } else if (query == 2) {
            if (uf.same(u, v)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
