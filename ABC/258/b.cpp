/* 問題
縦・横nのマス目に1~9の数字が書かれている。好きなマスから縦・横・斜めの８方向にn-1回移動する。通ったマスに書かれている数字を左から順番に並べた整数として最大のものを求める。このマスは上下及び左右がつながっていることに注意。
    ・(1,i) の上のマスは(N,i) であり、(N,i) の下のマスは(1,i) である。(1≤i≤N)
    ・(i,1) の左のマスは(i,N) であり、(i,N) の右のマスは(i,1) である。(1≤i≤N)

制約
1 <= n <= 10
1 <= a[i][j] <= 9
入力は全て整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// 制約が小さいので、問題文の通りに実装し、全探索で解く

int main() {
    int n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }

    const vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    const vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int dir = 0; dir < 8; ++dir) {
                ll now = 0;
                ll x = i, y = j;
                for (int k = 0; k < n; ++k) {
                    now *= 10;
                    now += a[x][y];
                    x += dx[dir], y += dy[dir];
                    x %= n;
                    x += n;
                    y %= n;
                    y += n;
                    x %= n;
                    y %= n;
                }
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
