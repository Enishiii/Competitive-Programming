/*
問題文
高橋君は英小文字からなる文字列T を青木君に向けて送りました。その結果、青木君は英小文字からなる文字列T′ を受信しました。
T′ はT から一部が変更されてしまっている可能性があり、具体的には、下記の
4 つのうちのちょうど1 つが成り立つことがわかっています。
    ・T′ は、T と等しい。
    ・T′ は、T のいずれか1 つの位置（先頭と末尾も含む）に英小文字を1 つ挿入して得られる文字列である。
    ・T′ は、T からある1 文字を削除して得られる文字列である。
    ・T′ は、T のある1 文字を別の英小文字に変更して得られる文字列である。
青木君が受信した文字列T′ と、英小文字からなるN 個の文字列S1,S2,…,SN が入力として与えられるので、S1,S2,…,SN のうち、高橋君が送った文字列
T と等しい可能性があるものをすべて求めてください。

制約
N は整数
1≤N≤5×10^5
Si とT′ は英小文字からなる長さ1 以上5×10^5 以下の文字列
S1,S2,…,SN の長さの総和は5×10^5 以下
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_valid(const string &t, const string &s) {
    int len_diff = t.size() - s.size();

    // ケース1と4（同じ長さで異なる文字が1個以下）
    if (len_diff == 0) {
        int diff_count = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != s[i])
                ++diff_count;
            if (diff_count > 1)
                return false;
        }
        return true;
    }
    // ケース2と3（余分な/欠けている文字を除いて同一）
    else if (len_diff == 1 || len_diff == -1) {
        const string &longer = (len_diff == 1) ? t : s;
        const string &shorter = (len_diff == 1) ? s : t;

        int diff_idx = -1;
        for (int i = 0; i < shorter.size(); ++i) {
            if (longer[i] != shorter[i]) {
                diff_idx = i;
                break;
            }
        }

        // 差が見つからなかった場合、末尾に文字が追加/削除されているので有効
        if (diff_idx == -1)
            return true;

        // 残りの文字が等しいかどうか判定
        return longer.substr(diff_idx + 1) == shorter.substr(diff_idx);
    }
    return false;
}

int main() {
    int n;
    string Tp;
    cin >> n >> Tp;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    vector<int> valid_indices;
    for (int i = 0; i < n; ++i) {
        if (is_valid(Tp, s[i])) {
            valid_indices.push_back(i + 1);
        }
    }

    cout << valid_indices.size() << endl;
    for (int i = 0; i < valid_indices.size(); ++i) {
        if (i) cout << " ";
        cout << valid_indices[i];
    }
    cout << endl;

    return 0;
}
