/* 問題文
1 から N の番号が付いた N 人がコイントスを何回かしました。人 i はAi  回表を出し、
Bi  回裏を出したこと分かっています。
人i のコイントスの 成功率 は Ai/Ai +Bi  で定義されます。人 1,…,N の番号を、成功率の高い順に並び替えてください。成功率が同じ人が複数いる場合、その中では人の番号が小さい順になるように並び替えてください。

制約
2≤N≤2×10^5
0≤Ai,Bi ≤10^9
Ai +Bi ≥1
入力される数値は全て整数*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ab;
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ab.emplace_back(a, a+b);
    }

    // 0からn-1までのインデックスのリストを作成
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);

    // 愚直にdoubleを使ってa[i]/a[i]+b[i]を計算すると、誤差が生まれてしまう。
    // a[i]/a[i]+b[i]とa[j]/a[j]+b[j]を比較するのではなく、分母を払ってあげてa[i]*(a[j]+b[j])とa[j]*(a[i]+b[i])を比較する

    // ソートのための比較関数
    auto f = [&](int i, int j) {
        auto [ai, aj] = ab[i];
        auto [bi, bj] = ab[j];
        return (long long)ai * bj > (long long)aj * bi;
    };

    // 比較関数に基づいてインデックスをソート。sortは安定ソートではないので、stable_sortを使う。
    stable_sort(p.begin(), p.end(), f);

    // ソートされた順序でインデックスを出力(1加算)
    for (int i = 0; i < n; ++i) {
        cout << p[i] + 1 << (i == n-1 ? "\n" : " ");
    }

    return 0;
}
