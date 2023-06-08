/* 問題文
高橋キングダムには、高橋諸島という、N 個の島からなる諸島があります。 便宜上、これらの島を島 1、島 2、 ...、島N と呼ぶことにします。
これらの諸島の間では、船の定期便がM 種類運行されています。 定期便はそれぞれ 2 つの島の間を行き来しており、i 種類目の定期便を使うと、 島ai​ と島bi​ の間を行き来する事ができます。
すぬけくんは今島 1 にいて、島N に行きたいと思っています。 しかし、島 1 から島N への定期便は存在しないことがわかりました。 なので、定期便を 2 つ使うことで、島N に行けるか調べたいと思っています。
これを代わりに調べてあげてください。

制約
3≦N≦200,000
1≦M≦200,000
1≦ai<bi≦N
(ai, bi) != (1, N)
i != j ならば(ai, bi) != (aj, bj) */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool ok = false;
    for (auto j : g[0]) {
        for (auto k : g[j]) {
            if (k == n-1) {
                ok = true;
                break;
            }
        }
    }

    if (ok) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}
