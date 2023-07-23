/* 問題文
1 からN までの番号がついたN 人の人がいます。
N 人の人の今後D 日間の予定が与えられます。人i の予定は長さ
D の文字列Si で表されて、Si のj 文字目が o ならばj 日目は暇であることを、x ならばそうでないことを意味します。
D 日間のうち全員が暇であるような 連続する 何日かを選ぶことを考えます。
選べる日数は最大で何日ですか？ただし、選べる日が存在しない場合は
0 日と答えてください。

制約
1≤N≤100
1≤D≤100
N,D は整数
Si は o と x からなる長さD の文字列 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    int cur = 0, ans = 0;
    for (int i = 0; i < d; ++i) {

        // 各日を見て、全員がoならcurを1増やす
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == 'x') ok = false;
        }

        if (ok) cur++;
        else cur = 0; // 1人でもxなら、連続する日数がリセットされるので、0に戻す

        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}
