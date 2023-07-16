/* 問題文
高橋君は、レストランで「AtCoder ドリンク」というドリンクを飲もうとしています。 AtCoder ドリンクは定価であるP 円を払えば飲むことができます。
また、高橋君は割引券を持っており、それを使うと AtCoder ドリンクを定価より安い価格であるQ 円で飲むことができますが、 その場合には AtCoder ドリンクの他に、N 品ある料理の中から1 つを追加で注文しなければなりません。i=1,2,…,N について、i 番目の料理の価格はDi 円です。
高橋君がドリンクを飲むため支払う合計金額の最小値を出力してください。

制約
1≤N≤100
1≤Q<P≤10^5
1≤Di≤10^5
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;

    vector<int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];

    sort(d.begin(), d.end());
    cout << min(q + d[0], p) << endl;

    return 0;
}
