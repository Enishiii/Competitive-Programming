/*
問題文
頂点に1 からN の番号が付いたN 頂点の重み付き無向完全グラフが与えられます。頂点i と頂点j (i<j) を結ぶ辺の重みはDi,j です。
以下の条件を満たすように何本かの辺を選ぶとき、選んだ辺の重みの総和としてあり得る最大値を求めてください。
    ・選んだ辺の端点はどの2 個も相異なる。

制約
2 ≤ N ≤ 16
1 ≤ Di,j ≤ 10^9
入力される数値は全て整数
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// DFSによる全探索解法（ラムダ式は実装の簡略化のため使用）
int main() {
    int n;
    cin >> n;

    vector<vector<int>> d(n+1, vector<int>(n+1));
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            cin >> d[i][j];
            d[j][i] = d[i][j]; // 無向グラフなので逆方向の重みも同じ
        }
    }
    // nが奇数の場合、次の計算のために1増やす
    if (n % 2 == 1) n++;

    ll ans = 0;
    vector<bool> used(n);

    auto dfs = [&](auto dfs, int index, ll weight) -> void {
        ans = max(ans, weight);
        if (index == n) return; // 全ての頂点を調べ終えたら終了

        if (used[index]) {
            dfs(dfs, index+1, weight); // すでに使われている頂点はスキップ
            return;
        }

        used[index] = true;
        for (int j = index+1; j < n; ++j) {
            if (used[j]) continue;
            used[j] = true;
            dfs(dfs, index+1, weight+d[index][j]); // 隣接する頂点を使って再帰
            used[j] = false;
        }
        used[index] = false;
    };
    dfs(dfs, 0, 0);

    cout << ans << endl;

    return 0;
}
