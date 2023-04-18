/* 問題文
以下の3 種類のクエリを高速に処理する、販売システムを実装してください。

クエリ1：価格がx 円の商品が追加される。
クエリ2：今ある商品の中の最小価格を答える。
クエリ3：最も安い商品が1 つ売れる。
ただし、最初は商品が1 つもなく、与えられるクエリの数はQ 個であるとします。

入力
Query[i] はi 回目のクエリの情報を表します。クエリ1 の場合は 1 x、クエリ2 の場合は 2、クエリ3 の場合は 3 という形式で与えられます。

出力
クエリ
2 の答えを、順番に出力してください。

制約
1 ≤ Q ≤ 100,000
商品の値段は1 以上1,000,000 以下の整数である
クエリ2 およびクエリ3 の時点では、一つ以上の商品が存在する
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int q;
    cin >> q;

    priority_queue<int, vector<int>, greater<int>> price;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            price.push(x);
        } else if (type == 2) {
            cout << price.top() << endl;
        } else if (type == 3) {
            price.pop();
        }
    }

    return 0;
}
