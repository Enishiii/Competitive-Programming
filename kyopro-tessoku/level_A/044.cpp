/* 問題文
長さN の配列A=[A1,…,AN] があり、最初はすべてのi についてAi=i となっています。あなたは配列に対してQ 回の操作を行います。j 回目の操作は文字列Queryj で表されます。
・変更操作：Queryj　=  1 x y のとき、Ax の値をy に変更する
・反転操作：Queryj =  2 のとき、配列A を逆順にする
・取得操作：Queryj =  3 x のとき、Ax の値を答える
すべての取得操作に対して、正しく答えるプログラムを作成してください。

制約
1 ≤ N ≤ 200000
1 ≤ Q ≤ 200000
どのタイミングでも、配列A の要素は1 以上10^9 以下の整数である */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i) arr[i] = i;

    // 反転かどうかのフラグを用意
    // reverseを使わずにすみ、高速化できる
    bool state = true;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;

        // 場合分けが多いのでswitch文を使う
        switch(t) {
            case 1:
                int x, y;
                cin >> x >> y;
                if (state) arr[x] = y;
                else arr[n - x + 1] = y;
                break;
            case 2:
                state = !state;
                break;
            case 3:
                cin >> x;
                if (state) cout << arr[x] << endl;
                else cout << arr[n - x + 1] << endl;
                break;
            default:
                break;
        }
    }

    return 0;
}
