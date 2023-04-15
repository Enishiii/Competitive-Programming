/* 問題文
3×3 のグリッドがあります. 上からi 番目で左からj 番目のマスを(i,j) で表すとき, マス(i,j) には数c[i][j] が書かれています.高橋君によると, 整数a1 ,a2 ,a3 ,b1 ,b2 ,b3 の値が決まっており, マス
(i,j) には数ai +bj が書かれているらしいです.
高橋君の情報が正しいか判定しなさい.

制約
ci,j(1≤i≤3,1≤j≤3) は0 以上100 以下の整数
*/

#include <iostream>
using namespace std;

int main() {
    int c[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> c[i][j];
        }
    }

    int a[3], b[3];
    a[0] = 0; // 暫定的に１つ決めてやると、残り8マス全てが決まる
    for (int i = 0; i < 3; ++i) b[i] = c[0][i] - a[0];
    for (int i = 0; i < 3; ++i) a[i] = c[i][0] - b[0];

    // 与えられたマスと矛盾しないかを判定する
    bool ok = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i] + b[j] != c[i][j]) {
                ok = false;
            }
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
