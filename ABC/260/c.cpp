#include <iostream>
using namespace std;

using ll = long long;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    ll red[12], blue[12]; // 各レベル(1~10)の宝石を1個持っている状態から、入手できるレベル1の青い宝石の個数

    red[1] = 0, blue[1] = 1; // レベル1の赤い宝石からは、レベル1の青い宝石は得られず、レベル1の青い宝石からはレベル1の青い宝石は1個得られる。

    for (int level = 2; level <= n; ++level) {
        // 問題文に従って計算する。
        // red[n]の計算にblue[n]の値が必要なので、blueの計算から行うことに注意
        blue[level] = red[level-1] + blue[level-1] * y;
        red[level] = red[level-1] + blue[level] * x;
    }

    cout << red[n] << endl;

    return 0;
}
