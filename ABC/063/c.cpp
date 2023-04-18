/* 問題文
あなたはコンピュータで試験を受けています。試験はN 問の問題からなり、
i 問目の問題の配点はsi です。それぞれの問題に対するあなたの解答は「正解」または「不正解」のいずれかとして判定され、正解した問題の配点の合計があなたの成績となります。あなたが解答を終えると、解答がその場で採点されて成績が表示される…はずでした。
ところが、試験システムに欠陥があり、成績が10 の倍数の場合は、画面上で成績が0 と表示されてしまいます。それ以外の場合は、画面に正しい成績が表示されます。この状況で、成績として画面に表示されうる最大の値はいくつでしょうか？

制約
入力値はすべて整数である。
1 ≤ N ≤ 100
1 ≤ si ≤ 100
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 入力を受け取ると同時に総和も求める
    vector<int> s(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sum += s[i];
    }

    // 総和が10の倍数でないなら、それが答え。
    // そうでないなら、10の倍数でない一番小さい数を引いた値が答え。10の倍数が１つもないなら、いくら引いても10の倍数であることは変わらないので0を出力。
    if (sum % 10 != 0) {
        cout << sum << endl;
        return 0;
    } else {
        sort(s.begin(), s.end());
        bool exist = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] % 10 != 0) {
                sum -= s[i];
                exist = true;
                break;
            }
        }
        if (exist) cout << sum << endl;
        else cout << 0 << endl;
    }

    return 0;
}
