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
    // マス目を受け取る
    int h, w;
    cin >> h >> w;
    vector<vector<int>> x(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) cin >> x[i][j];
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
            prefixSum[i][j] += prefixSum[i-1][j];
        }
    }

    // q個の質問を受け取り、都度答えを出力する
    // 全体の累積和から左端一列と上１行の累積和を引き、2回引いた左斜め上の角の累積和を足すと、求めたい答えになる
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--; // 0-indexedに合わせる

        int total = prefixSum[c][d];
        if (a > 0) total -= prefixSum[a-1][d];
        if (b > 0) total -= prefixSum[c][b-1];
        if (a > 0 && b > 0) total += prefixSum[a-1][b-1];
        cout << total << endl;
    }

        return 0;
}
