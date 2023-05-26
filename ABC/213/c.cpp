/* 問題文
H 行W 列の格子状にHW 枚のカードが並べられています。
i=1,…,N について、上からAi 行目、左からBi  列目にあるカードには数
i が書かれており、それ以外のHW−N 枚のカードには何も書かれていません。
これらのカードに対し、以下の2 種類の操作を可能な限り繰り返します。
    ・数の書かれたカードを含まない行が存在するとき、その行のカードを全て取り除き、残りのカードを上へ詰める
    ・数の書かれたカードを含まない列が存在するとき、その列のカードを全て取り除き、残りのカードを左へ詰める
操作が終了したとき、数が書かれたカードがそれぞれどこにあるか求めてください。なお、答えは操作の仕方に依らず一意に定まることが証明されます。

制約
1 ≤ H,W ≤ 10^9
1 ≤ N ≤ min(10^5, HW)
1 ≤ Ai ≤ H
1 ≤ Bi ≤ W
(Ai, Bi) は相異なる
入力に含まれる値は全て整数である */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 入力
    int h, w, n;
    cin >> h >> w >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    // 座標圧縮で解く
    vector<int> compressedA = a, compressedB = b;

    // 昇順に並べ替える
    sort(compressedA.begin(), compressedA.end());
    sort(compressedB.begin(), compressedB.end());

    // 重複を削除
    compressedA.erase(unique(compressedA.begin(), compressedA.end()), compressedA.end());
    compressedB.erase(unique(compressedB.begin(), compressedB.end()), compressedB.end());

    // 配列a[i], b[i]の各要素が、座標圧縮後の配列の何番目に当たるかを求め、それに置き換えていく
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(compressedA.begin(), compressedA.end(), a[i]) - compressedA.begin();
    }
    for (int i = 0; i < n; ++i) {
        b[i] = lower_bound(compressedB.begin(), compressedB.end(), b[i]) - compressedB.begin();
    }

    // 1-indexedで出力
    for (int i = 0; i < n; ++i) {
        cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
    }

    return 0;
}
