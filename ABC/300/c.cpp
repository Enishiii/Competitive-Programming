#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0; i < h; ++i) cin >> c[i];

    // i, jが有効範囲にあるかをチェック
    auto isOk = [&](int i, int j) {
        return i >= 0 && i < h && j >= 0 && j < w;
    };
    // バツ印かをチェック
    auto test = [&](int i, int j, int d) {
        for (auto& x : vector{+d, -d}) {
            for (auto& y : vector{+d, -d}) {
                int s = i + x, t = j + y;
                if (!isOk(s, t) || c[s][t] != '#') return false;
            }
        }
        return true;
    };

    int n = min(h, w);
    vector<int> ans(n+1);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (c[i][j] != '#') continue;
            if (test(i, j, 1)) {
                int d = 1; // バツ印のサイズ
                // どこまで大きくできるかを求める
                while(test(i, j, d+1)) d++;
                ans[d]++;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
