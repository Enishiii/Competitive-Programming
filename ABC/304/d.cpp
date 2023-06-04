/* 問題文
xy -平面上にいくつかのイチゴが載った長方形のケーキがあります。 ケーキは、長方形領域 {(x,y):0≤x≤W,0≤y≤H} をちょうど占めます。
ケーキには N 個のイチゴが載っており、i=1,2,…,N について、i 番目のイチゴの座標は
(pi ,qi ) です。2 個以上のイチゴが同一の座標にあることはありません。
高橋君は、このケーキを包丁で下記の通りにいくつかのピースに切り分けます。
まず、ケーキを通る y 軸に並行な A 本の異なる直線、直線 x=a1 、直線x=a2 、… 、直線x=aA  のそれぞれにそってケーキを切る。
次に、ケーキを通るx 軸に並行なB 本の異なる直線、直線y=b1、直線y=b2、... 、直線y=bB  のそれぞれにそってケーキを切る。
その結果、ケーキは (A+1)(B+1) 個の長方形のピースに分割されます。 高橋君はそれらのうちのいずれか 1 個だけを選んで食べます。 高橋君が選んだピースに載っているイチゴの個数としてあり得る最小値と最大値をそれぞれ出力してください。
ここで、最終的にピースの縁となる位置にはイチゴが存在しないことが保証されます。 より形式的な説明は下記の制約を参照してください。

制約
3≤W,H≤10^9
1≤N≤2×10^5
0<pi<W
0<qi<H
i != j ⟹ (pi,qi) !=(pj,qj)
1≤A,B≤2×10^5
0<a1<a2<⋯<aA<W
0<b1<b2<⋯<bB<H
pi !∈ {a1,a2,…,aA}
qi !∈ {b1,b2,…,bB}
入力はすべて整数 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    // ケーキの大きさとイチゴの数を入力
    int w, h, n;
    cin >> w >> h >> n;

    // イチゴの座標を入力
    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) cin >> p[i] >> q[i];

    // y軸に平行な直線の数と位置を入力
    int A;
    cin >> A;
    vector<int> a(A);
    for (int i = 0; i < A; ++i) cin >> a[i];

    // x軸に平行な直線の数と位置を入力
    int B;
    cin >> B;
    vector<int> b(B);
    for (int i = 0; i < B; ++i) cin >> b[i];

    // 各ピースに含まれるイチゴの数を計算
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
        int y = lower_bound(b.begin(), b.end(), q[i]) - b.begin();
        mp[pair(x, y)]++;
    }

    // 最小と最大のイチゴの数を求める
    int m = n, M = 0;
    for (auto e : mp) {
        m = min(m, e.second);
        M = max(M, e.second);
    }

    // 全てのピースがイチゴを含んでいない場合、最小値は0とする
    if (mp.size() < (long long)(A+1)*(B+1)) m = 0;

    // 最小値と最大値を出力
    cout << m << " " << M << endl;

    return 0;
}
