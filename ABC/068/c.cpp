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
    // 島の数(n)と定期便の数(m)を読み込む
    int numIslands, numRoutes;
    cin >> numIslands >> numRoutes;

    // それぞれの島がどの島とつながっているかを表現する二次元配列
    vector<vector<int>> graph(numIslands, vector<int>());
    for (int i = 0; i < numRoutes; ++i) {
        // 定期便の始点(a)と終点(b)を読み込む
        int a, b;
        cin >> a >> b;
        a--, b--;
        // 始点から終点、終点から始点への道を表現
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 島1から島Nへの経路が存在するかのフラグ
    bool routeExists = false;
    // 島1から直接行ける各島について
    for (auto island : graph[0]) {
        for (auto connectedIsland : graph[island]) {
            if (connectedIsland == numIslands - 1) {
                routeExists = true;
                break;
            }
        }
    }

    if (routeExists) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}
