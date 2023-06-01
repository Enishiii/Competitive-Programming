/* 問題文
l が奇数のとき，l 個の数a1, a2, ..., al の中央値とは，a1, a2, ..., al の中でl+1/2 番目に大きい値のことを言います．
N 個の数X1, X2, ..., XN が与えられます．ここで，N は偶数です．
i=1,2,...,N に対して，X1, X2, ..., XN からXi のみを除いたもの，すなわちX1, X2, ..., Xi−1, Xi+1, ..., XN の中央値をBi とします．
i=1,2,...,N に対して，Bi を求めてください．

制約
2 ≤ N ≤ 200000
N は偶数
1 ≤ Xi ≤ 10^9
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    // 入力
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[i] = x[i]; // 別の配列にコピー
    }

    sort(y.begin(), y.end());

    // xの各値が昇順で何番目かをmapに記録する
    map<int, int> idx;
    for (int i = n-1; i >= 0; --i) {
        idx[y[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        int j = idx[x[i]];

        // 昇順にソートした配列の半分よりも前にある値か、以降にある値かで出力する中央値が変わる
        if (j < n/2) cout << y[n/2] << endl;
        else cout << y[n/2-1] << endl;
    }

    return 0;
}
