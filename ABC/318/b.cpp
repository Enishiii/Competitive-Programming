/* 問題文
座標平面上に N 枚の長方形のシートが張られています。
各シートが覆う長方形領域の各辺はそれぞれ x 軸または y 軸と平行であり、
具体的には、i 枚目のシートはちょうど Ai≤x≤Bi かつCi≤y≤Di をみたす領域全体を覆っています。
1 枚以上のシートによって覆われている領域 の面積を S とすると、 S は制約の条件下で整数となる事が証明できます。
S を整数の形で出力してください。

制約
2 ≤ N ≤ 100
0 ≤ Ai < Bi ≤ 100
0 ≤ Ci < Di ≤ 100
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    int coveredArea = 0;

    // 0から100までのすべての座標点を順にチェック
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {

            // その点が1つ以上のシートで覆われているかを判定する
            for (int i = 0; i < n; ++i) {
                if (a[i] <= x && x < b[i] && c[i] <= y && y < d[i]) {
                    coveredArea++;
                    break; // 1つ以上のシートで覆われているので、次の座標に移動する
                }
            }
        }
    }

    cout << coveredArea << endl;

    return 0;
}
