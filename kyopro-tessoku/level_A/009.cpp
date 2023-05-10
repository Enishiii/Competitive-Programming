/* 問題文
ALGO 王国はH×W のマス目で表されます．最初は，どのマスにも雪が積もっていませんが，これからN 日間にわたって雪が降り続けます．
上からi 行目，左からj 列目のマスを(i,j) とするとき，t 日目には 「マス(At, Bt) を左上とし，マス(Ct, Dt) を右下とする長方形領域」の積雪が1cm だけ増加することが予想されています． 最終的な各マスの積雪を出力するプログラムを作成してください．

制約
1 ≤ H,W ≤ 1500
1 ≤ N ≤ 100000
1 ≤ Ai ≤ Ci ≤ H
1 ≤ Bi ≤ Di ≤ W
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n+1), b(n+1), c(n+1), d(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    // 差分を取った二次元配列と累積和の二次元配列を用意
    vector<vector<int>> diff_matrix(h+2, vector<int>(w+2)), prefix_sum_matrix; // 配列の添字が制約の範囲を超えないように、配列のサイズを確保する
    prefix_sum_matrix = diff_matrix;

    // 左上と右下の右隣を＋1、右上と左下を−1する（これで二次元累積和をとれば、求めたい二次元配列になる）
    for (int i = 1; i <= n; ++i) {
        diff_matrix[a[i]][b[i]] += 1;
        diff_matrix[a[i]][d[i] + 1] -= 1;
        diff_matrix[c[i] + 1][b[i]] -= 1;
        diff_matrix[c[i] + 1][d[i] + 1] += 1;
    }

    // 横の累積和
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            prefix_sum_matrix[i][j] = prefix_sum_matrix[i][j - 1] + diff_matrix[i][j];
        }
    }

    // 縦の累積和
    for (int j = 1; j <= w; ++j) {
        for (int i = 1; i <= h; ++i) {
            prefix_sum_matrix[i][j] += prefix_sum_matrix[i - 1][j];
        }
    }

    // 出力
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (j > 1) cout << " ";
            cout << prefix_sum_matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}
