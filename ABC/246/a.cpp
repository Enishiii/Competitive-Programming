/* 問題文
xy 平面上に長方形があります。この長方形の各辺は x 軸または y 軸に平行であり、面積は
0 ではありません。
この長方形の 4 つの頂点のうち異なる 3 つの頂点の座標 (x1,y1),(x2,y2),(x3,y3) が与えられるので、残る 1 つの頂点の座標を求めてください。

制約
−100≤xi,yi≤100
(x1,y1),(x2,y2),(x3,y3) のすべてを頂点に持つ長方形がただ一つ存在し、その各辺は x 軸または y 軸に平行であり、面積は 0 ではない。
入力はすべて整数 */

#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

Point findFourthPoint(Point p1, Point p2, Point p3) {
    Point p4;

    p4.x = (p1.x == p2.x) ? p3.x : ((p1.x == p3.x) ? p2.x : p1.x);
    p4.y = (p1.y == p2.y) ? p3.y : ((p1.y == p3.y) ? p2.y : p1.y);

    return p4;
}

int main() {
    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    Point p4 = findFourthPoint(p1, p2, p3);

    cout << p4.x << " " << p4.y << endl;

    return 0;
}
