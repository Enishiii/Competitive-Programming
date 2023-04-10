/* xy平面があって、n人が（a[i], b[i])(1<=i<=n)の座標にいて、チェックポイントが(c[j], d[j])(1<=j<=m)にある。各人の最も近いチェックポイント（マンハッタン距離）の番号を求めよ。距離が同じなら、番号が小さい方のチェックポイントの番号を出力せよ。
1<=n, m<=50
-10^8 <= a[i], b[i], c[j], d[j] <= 10^8
入力は全て整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int j = 0; j < m; ++j) cin >> c[j] >> d[j];

    // n, mが小さいので、二重ループで全探索して最も近いものを求める
    for (int i = 0; i < n; ++i) {
        int cur = 1e18, ans = 0;
        for (int j = 0; j < m; ++j) {
            int dist = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if (cur == dist) continue;
            else if (cur > dist) {
                cur = dist;
                ans = j+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
