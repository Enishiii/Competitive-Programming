/* 問題文
AtCoder 商店には N 個の商品があります。
i (1≤i≤N) 番目の商品の価格は Pi です。
i (1≤i≤N) 番目の商品は Ci 個の機能をもち、i (1≤i≤N) 番目の商品のj (1≤j≤Ci) 番目の機能は
1 以上 M 以下の整数Fi,j として表されます。
高橋くんは、AtCoder 商店の商品で一方が一方の上位互換であるものがないか気になりました。 i 番目の商品とj 番目の商品(1≤i,j≤N) であって、次の条件をすべて満たすものがあるとき Yes と、ないとき No と出力してください。
・Pi ≥Pj である。
・j 番目の製品はi 番目の製品がもつ機能をすべてもつ。
・Pi >Pj であるか、j 番目の製品はi 番目の製品にない機能を1 つ以上もつ。

制約
2≤N≤100
1≤M≤100
1≤Pi ≤10^5(1≤i≤N)
1≤Ci ≤M (1≤i≤N)
1≤Fi,1 <Fi,2<⋯<Fi,Ci ≤M (1≤i≤N)
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n), c(n);
    vector<set<int>> f(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> c[i];
        f[i] = set<int>();
        for (int j = 0; j < c[i]; ++j) {
            int feature;
            cin >> feature;
            f[i].insert(feature);
        }
    }

    bool ans = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool priceCondition = p[i] >= p[j];
            bool isSuperset = includes(f[j].begin(), f[j].end(), f[i].begin(), f[i].end());
            bool extraFeatureCondition = p[i] > p[j] || f[j].size() > f[i].size();
            ans |= priceCondition && isSuperset && extraFeatureCondition;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}
