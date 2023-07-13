/* 問題文
1 からN までの番号がついたN 人の参加者が、1 からM までの番号がついた
M 問からなるコンテストに参加します。
1 以上N 以下の整数i 、1 以上M 以下の整数j について、Si のj 番目の文字が o のとき参加者i は問題j を解くことが可能で、Si のj 番目の文字が x のとき参加者i は問題j を解くことが不可能です。
このコンテストは、二人の参加者でペアを組んで参加します。二人が協力することでM 問全てを解くことが可能であるようなペアの個数を答えてください。
より厳密には、1≤x<y≤N を満たす整数の組(x,y) であって、1 以上M 以下の任意の整数j について、参加者x か参加者y の少なくとも一方は問題j を解くことが可能であるという条件を満たすものの個数を答えてください。

制約
N は2 以上30 以下の整数
M は1 以上30 以下の整数
Si は o, x からなる長さM の文字列 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int ans = 0;

    // 制約が小さいので、二重ループで全探索して条件を満たすかを判定する
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool ok = true;
            for (int k = 0; k < m; ++k) {
                if (s[i][k] == 'x' && s[j][k] == 'x') ok = false;
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
