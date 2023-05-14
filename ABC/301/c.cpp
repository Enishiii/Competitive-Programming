/* 問題文
AtCoder社ではカードを使った1 人ゲームが流行っています。
ゲームで使う各カードには、英小文字1 文字または @ の文字が書かれており、いずれのカードも十分多く存在します。
ゲームは以下の手順で行います。
1. カードを同じ枚数ずつ2 列に並べる。
2. @ のカードを、それぞれ a, t, c, o, d, e, r のいずれかのカードと置き換える。
3. 2 つの列が一致していれば勝ち。そうでなければ負け。
このゲームに勝ちたいあなたは、次のようなイカサマをすることにしました。
・手順1 以降の好きなタイミングで、列内のカードを自由に並び替えてよい。
手順1 で並べられた2 つの列を表す2 つの文字列S,T が与えられるので、イカサマをしてもよいときゲームに勝てるか判定してください。

制約
S,T は英小文字と @ からなる
S,T の長さは等しく1 以上2×10^5 以下 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    // sとtの各アルファベットの個数と、＠の個数を数える
    vector<int> s_count(26, 0);
    vector<int> t_count(26, 0);
    int s_at = 0, t_at = 0;

    for (char c : s) {
        if (c == '@') s_at++;
        else s_count[c - 'a']++;
    }

    for (char c : t) {
        if (c == '@') t_at++;
        else t_count[c - 'a']++;
    }

    // 各アルファベットの個数について見ていく。同じなら、そのまま。違うなら＠を使って調整
    // atcoderの各アルファベットのみ＠での調整が可能であることに注意。
    // 調整ができないと判明した段階でNoを出力し、終了する
    string atcoder = "atcoder";
    for (int i = 0; i < 26; ++i) {
        if (s_count[i] != t_count[i]) {
            char c = i + 'a';
            if (atcoder.find(c) == string::npos) {
                cout << "No" << endl;
                return 0;
            }

            if (s_count[i] > t_count[i]) {
                int diff = s_count[i] - t_count[i];
                if (diff > t_at) {
                    cout << "No" << endl;
                    return 0;
                } else {
                    t_at -= diff;
                }
            } else {
                int diff = t_count[i] - s_count[i];
                if (diff > s_at) {
                    cout << "No" << endl;
                    return 0;
                } else {
                    s_at -= diff;
                }
            }
        }
    }
    // 最後までNoにならなかった時はYes
    cout << "Yes" << endl;

    return 0;
}
