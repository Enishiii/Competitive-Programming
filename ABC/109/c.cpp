/* 問題文
数直線上にN 個の都市があり、i 番目の都市は座標xi にあります。
あなたの目的は、これら全ての都市を1 度以上訪れることです。
あなたは、はじめに正整数D を設定します。
その後、あなたは座標X から出発し、以下の移動1、移動2 を好きなだけ行います。
    ・移動1: 座標y から座標y+D に移動する
    ・移動2: 座標y から座標y−D に移動する
全ての都市を1 度以上訪れることのできるD の最大値を求めてください。
ここで、都市を訪れるとは、その都市のある座標に移動することです。

制約
入力はすべて整数である
1 ≤ N ≤ 10^5
1 ≤ X ≤ 10^9
1 ≤ xi ≤ 10^9
xi はすべて異なる
x1, x2, ..., xN != X */

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int n, X;
    cin >> n >> X;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    // Xから各座標までの距離を求め、その最大公約数を求める
    // 全ての都市が出発地点からDの倍数の距離に存在しなければならないため。
    int diff = abs(X - x[0]);
    for (int i = 1; i < n; ++i) {
        diff = gcd(diff, abs(X - x[i]));
    }
    cout << diff << endl;

    return 0;
}
