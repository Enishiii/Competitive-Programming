/* 問題文
英小文字のみからなる N 個の文字列 S1,S2,…,SN が与えられます。
S1,S2,…,SN  から文字列を好きな個数選ぶことを考えます。
このとき、「選んだ文字列の中でちょうど K 個の文字列に登場する英小文字」の種類数としてあり得る最大値を求めてください。

制約
1≤N≤15
1≤K≤N
N,K は整数
Si は英小文字からなる空でない文字列である。
1≤i≤N を満たす整数 i に対し、Si  に同じ文字は 2 個以上含まれない。
i !=j ならばSi != Sj  である。*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> s(n);
    for (string& str : s) cin >> str;

    int maxOccurrence = 0;

    // 各文字列は、選ぶ/選ばないの２通りあるので、N個の文字列からいくつか選ぶ方法は2^N通りある。
    // ビット全探索で全て調べ上げて解く。（Nが非常に小さいので可能）
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<int> charCount(26, 0);
        for (int idx = 0; idx < n; ++idx) {
            // idx番目の文字列を選ぶ
            if ((bit >> idx) & 1) {
                // 各文字の出現数を調べてインクリメント
                for (char c : s[idx]) charCount[c - 'a']++;
            }
        }
        // 目的の出現数を達成した文字の数を計算
        int currentOccurrence = count(charCount.begin(), charCount.end(), k);

        // 最大出現数を更新
        maxOccurrence = max(maxOccurrence, currentOccurrence);
    }
    cout << maxOccurrence << endl;

    return 0;
}
