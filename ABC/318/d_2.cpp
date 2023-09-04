#include <iostream>
#include <vector>
using namespace std;

// ビットDPによる解法
int main() {
    int n;
    cin >> n;

    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            cin >> d[i][j];
        }
    }

    // dp[mask]は、maskに示される頂点集合で得られる最大の重みを保存
    vector<long long> dp(1 << n, 0);
    for (int mask = 0; mask < (1 << n) - 1; ++mask) {
        // 未訪問の頂点を見つける
        int first_unvisited = -1;
        for (int i = 0; i < n; ++i) {
            if (!(mask >> i & 1)) {
                first_unvisited = i;
                break;
            }
        }

        for (int i = 0; i < n; ++i) { // 全ての頂点を調べる
            if (!(mask >> i & 1)) { // 頂点iがまだ訪問されていない場合
                // 頂点iとfirst_unvisitedを結んだ、頂点集合を求める
                int new_mask = mask | (1 << first_unvisited) | (1 << i);
                dp[new_mask] = max(dp[new_mask], dp[mask] + d[first_unvisited][i]);
            }
        }
    }

    cout << dp.back() << endl;

    return 0;
}
