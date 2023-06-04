/* 問題文
1,2,…,N の番号がついたN 人の人が二次元平面上におり、人i は座標
(Xi,Yi) で表される地点にいます。
人1 がウイルスに感染しました。ウイルスに感染した人から距離が
D 以内にいる人にウイルスはうつります。
ただし、距離はユークリッド距離、すなわち2 点(a1,a2) と(b1,b2) に対し、この2 点間の距離がsqrt((a1−b1)^2+(a2−b2)^2 であるものとして定められています。
十分に時間が経過した、すなわち人i がウイルスに感染しているならば 人
i との距離がD 以内にいるすべての人がウイルスに感染している状態になったときに、各i について人i がウイルスに感染しているか判定してください。

制約
1≤N,D≤2000
−1000≤Xi,Yi ≤1000
i != j のとき(Xi,Yi) != (Xj,Yj)
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Union-Find木を実装するための構造体
struct UnionFind {
    // 各ノードの親を保持する配列。初期値は-1(自身がルートを意味する)
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}

    // ノードxのルートを取得
    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // ノードxとyを結合する
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    // ノードxとyが同じ集合に属しているかどうかを判断
    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    // 人数nと感染距離dを取得
    int n, d;
    cin >> n >> d;

    // 各人の位置を保持するベクトル
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // ユークリッド距離が感染距離以下の場合、2人を同じグループに結合
            if (sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) <= d) {
                uf.unite(i, j);
            }
        }
    }

    // 各人がウイルスに感染しているか（人1と同じグループにいるか)を表示
    for (int i = 0; i < n; ++i) {
        if (uf.same(0, i))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
