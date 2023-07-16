/* 問題文
ボールがいくつか刺さった棒が N 本あり、各ボールには英小文字が 1 個書かれています。
i=1,2,…,N について、i 番目の棒に刺さった各ボールの英小文字は、文字列 Si によって表されます。 具体的には、i 番目の棒には文字列 Si の長さ∣Si∣ に等しい個数のボールが刺さっており、 刺さっているボールの英小文字を、棒のある端から順に並べたものは文字列
Si と等しいです。
2 つの棒は、一方の棒に刺さっているボールの英小文字をどちらかの端から並べた列と、もう一方の棒に刺さっているボールの英小文字をどちらかの端から並べた列が一致するとき、同じ棒とみなされます。 より形式的には、1 以上N 以下の整数i,j について、i 本目の棒と j 本目の棒は、Si がSj と一致するか、Si がSj を前後反転したものと一致するとき、かつそのときに限り、同じとみなされます。
N 本の棒の中に、何種類の異なる棒があるかを出力してください。

制約
N は整数
2≤N≤2×10^5
Si は英小文字のみからなる文字列
∣Si∣≥1
∑ (i=1...N) ∣Si∣≤2×10^5 */

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    set<string> st;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (st.count(s) == 0) ans++;
        st.insert(s);
        reverse(s.begin(), s.end());
        st.insert(s);
    }

    cout << ans << endl;

    return 0;
}
