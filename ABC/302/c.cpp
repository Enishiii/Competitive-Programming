/* 問題文
英小文字からなる長さM の文字列N 個S1,S2,…,SN が与えられます。ここで、Si は互いに異なります。
これらを並び替えた文字列の列T1,T2,…,TN であって、以下の条件を満たすものが存在するか判定してください。
    ・1≤i≤N−1 を満たす全ての整数i に対して、Ti を1 文字だけ別の英小文字に変えてTi+1 にすることが出来る。

制約
2 ≤ N ≤ 8
1 ≤ M ≤ 5
Si は英小文字からなる長さM の文字列である。(1≤i≤N)
Si は互いに異なる。 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2つの文字列を前から１文字ずつ比較し、差分合計が1であればtrueを返す
bool is_diff_by_one(string s, string t) {
    int diff = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i])
            diff++;
    }
    return (diff == 1);
}

int main() {
    // 入力
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    // next_permutationでsの並びを全て試す(n!個のパターン)
    // 隣り合う文字列との差分が全て1になるsの並びを見つける
    // O(n! * (n*m)) -> n, mが非常に小さいので問題なし
    sort(s.begin(), s.end());
    do {
        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            if (!is_diff_by_one(s[i], s[i + 1])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << "No" << endl;

    return 0;
}
