/* 問題文
英大文字と数字からなる文字列S が与えられるので、S が以下の条件を満たすか判定してください。
    ・S は次の文字または文字列をこの順番で連結して得られる。
        ・一文字の英大文字
        ・100000 以上999999 以下の整数を10 進表記して得られる長さ6 の文字列
        ・一文字の英大文字
制約
S は英大文字と数字からなる
S の長さは1 以上10 以下 */

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    // １つ目の条件
    bool first = isupper(s[0]);

    // 2つ目の条件
    string t = s.substr(1, s.size()-2);
    bool num = t[0] != '0' && isdigit(t[0]);
    for (int i = 1; i < t.size(); ++i) {
        if (!isdigit(t[i])) num = false;
    }

    // ３つ目の条件
    bool last = isupper(s.back());

    if (first && num && last) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
