/* 問題文
平面上に長方形があり、4 つの頂点の座標は (0,0),(W,0),(W,H),(0,H) です。 この長方形の内部または周上の点 (x,y) が与えられます。
(x,y) を通る直線で長方形を 2 つの部分に分割するとき、 面積の大きくない方の面積の最大値を求めてください。また、その最大値を達成する分割の方法が複数あるかも判定してください。

制約
1≤W,H≤10^9
0≤x≤W
0≤y≤H
入力はすべて整数である */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long w, h, x, y;
    cin >> w >> h >> x >> y;

    // 与えられた点(x, y)と長方形の中心を通るような直線で長方形を切れば、小さい方の面積が全体の半分になり、求めたい最大値である
    double half = w * h / 2.0;

    // 点(x, y)が長方形の中心であれば、長方形を半分に切る方法は複数存在する
    int multi = 0;
    if (x * 2 == w && y * 2 == h) multi = 1;

    cout << fixed << setprecision(10) << half << " " << multi << "\n";

    return 0;
}
