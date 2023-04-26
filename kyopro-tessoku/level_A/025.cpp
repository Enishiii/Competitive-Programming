/* 問題文
縦H 行、横W 列のマス目があります。
上からi 行目・左からj 列目のマス(i, j)は色c[i][j]​ で塗られています。
ここでc[i][j]が .ならば白、c[i][j]が #ならば黒を意味します。
マス(1, 1) から出発し、右方向または下方向の移動のみを繰り返して、マス(H, W) まで行く方法は何通りありますか。
ただし、黒いマスを通ることはできないものとします。

制約
2≤H≤30
2≤W≤30
c[i][j]は.または #である
c[1][1] は.である
c[H][W] は.である */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0; i < h; ++i) cin >> c[i];

    // 動的計画法
    long long dp[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i == 0 && j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = 0;
                if (i > 0 && c[i-1][j] == '.') dp[i][j] += dp[i-1][j];
                if (j > 0 && c[i][j-1] == '.') dp[i][j] += dp[i][j-1];
            }
        }
    }
    cout << dp[h-1][w-1] << endl;

    return 0;
}
