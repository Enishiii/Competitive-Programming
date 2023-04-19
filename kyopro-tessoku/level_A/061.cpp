/* 問題文
頂点数N、辺数M のグラフが与えられます。頂点には1 からN までの番号が付けられており、i 番目の辺は頂点Ai とBi を双方向に結んでいます。 それぞれのk について、「頂点k と隣接している頂点の番号」をすべて出力するプログラムを作成してください。

制約
2 ≤ N ≤ 100000
1 ≤ M ≤ 100000
1 ≤ Ai < Bi ≤ N (1 ≤ i ≤ M)
i != j ⟹ (Ai,Bi) != (Aj,Bj)
入力は全て整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 隣接リストで入力を受け取る
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b);
        g[b-1].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        cout << i+1 << ": {";
        for (int j = 0; j < g[i].size(); ++j) {
            if (j) cout << ", ";
            cout << g[i][j];
        }
        cout << "}" << endl;
    }

    return 0;
}
