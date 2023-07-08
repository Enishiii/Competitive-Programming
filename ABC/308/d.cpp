/* 問題文
H 行 W 列のグリッドがあります。 以下、上から i 行目、左から j 列目のマスを (i,j) と表記します。 グリッドの各マスには英小文字が書かれており、(i,j) に書かれた文字は与えられる文字列 Si  のj 文字目と一致します。
すぬけくんは、辺で隣接するマスに移動することを繰り返して (1,1) から (H,W) まで移動しようと思っています。 訪れるマス （最初の (1,1) と 最後の (H,W) を含む）に書かれた文字が、 訪れる順に s → n→ u→ k→ e→ s→ n→… となるような経路が存在するか判定してください。 なお、2 つのマス(i1,j1),(i2,j2) は∣i1−i2∣+∣j1−j2∣=1 を満たすとき、またそのときに限り「辺で隣接する」といいます。
より厳密には、マスの列 ((i1,j1),(i2,j2),…,(ik,jk)) であって以下の条件を全て満たすものが存在するか判定してください。
    ・(i1,j1)=(1,1),(ik,jk)=(H,W)
    ・すべての t (1≤t<k) について、(it,jt) と(it+1,jt+1) は辺で隣接する
    ・すべてのt (1≤t≤k) について、(it,jt) に書かれた文字は snuke の ((t−1)mod5)+1 文字目と一致する

制約
2≤H,W≤500
H,W は整数
Si  は英小文字からなる長さ W の文字列 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    if (s[0][0] != 's') {
        cout << "No" << endl;
        return 0;
    }

    // 各文字の次の文字を示すマップを用意（アクセス高速化のため配列を使用）
    vector<char> nextChar(256); // 256はASCII文字セットの全範囲をカバーするサイズ
    nextChar['s'] = 'n';
    nextChar['n'] = 'u';
    nextChar['u'] = 'k';
    nextChar['k'] = 'e';
    nextChar['e'] = 's';

    const vector<int> dx = {0, 0, 1, -1};
    const vector<int> dy = {1, -1, 0, 0};

    vector visited(h, vector<bool>(w));

    auto dfs = [&](auto &self, int x, int y) -> void {
        visited[x][y] = true;
        for (int k = 0; k < 4; ++k) {
            int newX = x + dx[k];
            int newY = y + dy[k];

            // 新たな座標のバリデーション
            if (newX < 0 || newX >= h || newY < 0 || newY >= w) continue; // 範囲内にあるかどうか
            if (s[newX][newY] != nextChar[s[x][y]]) continue; // 次の文字と等しいか
            if (visited[newX][newY]) continue; // まだ訪れていないか

            // 新たな地点に移動（再帰呼び出し）
            self(self, newX, newY);
        }
    };

    dfs(dfs, 0, 0);

    cout << (visited[h-1][w-1] ? "Yes" : "No") << endl;

    return 0;
}
