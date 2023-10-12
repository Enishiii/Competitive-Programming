// 問題文
// 2 次元平面上の原点に高橋君がいます。
// 高橋君が 1 歩歩くと、いまいる点からのユークリッド距離がちょうどR であるような点に移動することができます(移動先の座標が整数である必要はありません)。これ以外の方法で移動することはできません。
// 高橋君が点 (X,Y) に到達するまでに必要な歩数の最小値を求めてください。
// なお、点 (x1,y1) と点(x2,y2) のユークリッド距離は sqrt((x1−x2)^2+(y1−y2)^2) で与えられます。

// 制約
// 1≤R≤10^5
// 0≤X,Y≤10^5
// (X,Y)!=(0,0)
// 入力は全て整数


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r, x, y;
    cin >> r >> x >> y;

    double d = sqrt(x * 1.0 * x + y * 1.0 * y);

    if (d == r) {
        cout << 1 << endl;
    } else if (d <= 2 * r) { // 半径Rの円を起点に、原点を中心とした2Rの円のどこでも行ける
        cout << 2 << endl;
    } else {
        cout << ceil(d / r) << endl; // 距離が2R以下になるまで目的地に真っ直ぐ移動し、残りを2番目のケースに基づいて2歩で移動する、と捉える。
    }

    return 0;
}