/* 問題文
H×W のマス目があります．上からi 行目，左からj 列目にあるマス(i,j) には，整数Xi,j が書かれています． これについて，以下のQ 個の質問に答えるプログラムを作成してください．
・i 個目の質問：左上(Ai,Bi) 右下(Ci,Di) の長方形領域に書かれた整数の総和は？
制約
1 ≤ H, W ≤ 1500
1 ≤ Q ≤ 100000
0 ≤ Xi,j ≤ 9
1 ≤ Ai ≤ Ci ≤ H
1 ≤ Bi ≤ Di ≤ W
入力はすべて整数 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int h, w;
    cin >> h >> w;

    vector<vector<int>> x(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) cin >> x[i][j];
    }

    int q;
    cin >> q;
    vector<int> a(q), b(q), c(q), d(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--, c[i]--, d[i]--; // 0-indexedに合わせる
    }

    // 二次元の累積和を用意
    vector<vector<int>> prefixSum(h, vector<int>(w));

    // まず横の累積和をとる
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (j == 0) prefixSum[i][j] = x[i][j];
            else prefixSum[i][j] = prefixSum[i][j-1] + x[i][j];
        }
    }

    // 次に縦の累積和をとる
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0) continue;
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j];
        }
    }

    // 全体から左端一列と上１行を切り取って、2回引いた左斜め上の角を足すと、求めたい答えになる
    for (int i = 0; i < q; ++i) {
        int total = prefixSum[c[i]][d[i]];
        if (a[i] > 0) total -= prefixSum[a[i]-1][d[i]];
        if (b[i] > 0) total -= prefixSum[c[i]][b[i]-1];
        if (a[i] > 0 && b[i] > 0) total += prefixSum[a[i]-1][b[i]-1];
        cout << total << endl;
    }

        return 0;
}
