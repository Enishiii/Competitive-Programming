/* 問題文
以下の3 種類のクエリを高速に処理するプログラムを実装してください。
・クエリ1：x と書かれたカードが机に置かれる。
・クエリ2：x と書かれたカードが机から除去される。
・クエリ3：机にあるx 以上のカードのうち最小のものを答える。
ただし、最初の時点では机の上に1 個もカードが置かれていないものとします。

入力
Queryi はi 回目のクエリの情報を表します。クエリ 1 の場合は 1 x、クエリ 2 の場合は 2 x、クエリ 3 の場合は 3 x という形式で与えられます。

出力
クエリ3 の答えを、順番に出力してください。ただし、x 以上のカードが机の上に存在しないクエリについては、−1 と出力してください。

制約
1 ≤ Q ≤ 100,000
1 ≤ x ≤ 10^9
クエリ1 では、既に置かれているカードが追加されることはない
クエリ2 では、置かれていないカードが除去されることはない
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;

    // setで与えられた数を管理する
    set<int> cards;
    for (int i = 0; i < q; ++i) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            cards.insert(x);
        } else if (t == 2) {
            cards.erase(x);
        } else if (t == 3) {
            auto itr = cards.lower_bound(x); // x以上の最小の値の添字
            if (itr == cards.end()) cout << -1 << endl; // もしset内の最大値（cards.end()）と添字が等しいなら、x以上の最小値は存在しない
            else cout << (*itr) << endl;
        }
    }

    return 0;
}
