/* 問題文
1,2,…,N がちょうど3 回ずつ現れる長さ3N の数列A=(A1,A2,…,A3N) が与えられます。
i=1,2,…,N について、A の中にあるi のうち真ん中にあるものの添字を
f(i) と定めます。1,2,…,N をf(i) の昇順に並べ替えてください。
f(i) の定義は厳密には以下の通りです。
    ・Aj=i を満たすj がj=α,β,γ (α<β<γ) であるとする。このとき、
f(i)=β である。

制約
1≤N≤10^5
1≤Aj≤N
i=1,2,…,N それぞれについて、A の中にi はちょうど3 回現れる
入力は全て整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 2回目に登場するものを順番に答え用配列に入れていき、それを順に出力するだけ

    vector<int> count(n+1, 0);
    vector<int> ans;

    for (int i = 0; i < 3 * n; ++i) {
        int a;
        cin >> a;
        count[a]++;
        if (count[a] == 2) ans.push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
