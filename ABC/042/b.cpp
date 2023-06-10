/* 問題文
いろはちゃんは 長さL の文字列をN 個持っており、それぞれS1,S2,...,SN です。
それらの文字列を好きな順番で全て結合してできる文字列のうち、もっとも辞書順で小さいものを求めてください。
なお、ある文字列s=s1s2s3...sn とt=t1t2t3...tm について、以下のどちらかを満たすとき、辞書順比較でs<t であるといいます。
    ・ある整数i(1≦i≦min(n,m)) に関して、1≦j<i を満たす任意の整数j においてsj=tj が成立し、かつsi<ti が成立する。
    ・任意の整数i(1≦i≦min(n,m)) に関してsi=ti が成立し、かつn<m が成立する。
制約
1≦N,L≦100
全てのi(1≦i≦N) に対し、Si の長さはL に等しい。
各i について,Si は全て半角英小文字のみから成る文字列である。 */

#include <iostream>
#include <vector>
#include <algorithm>
    using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<string> s(n);
    string ans = "";

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < n; ++i) ans += s[i];

    cout << ans << endl;

    return 0;
}
