/* 問題文
高橋君は RPG を作っています。高橋君は 2 枚の RPG 世界のマップが一致しているかを判定するプログラムを書くことにしました。
縦H マス横W マスの 2 つのグリッドA,B があります。グリッドの各マスには #と.のいずれかの文字が書かれています。
A とB の上からi 行目、左からj 列目に書かれている文字をそれぞれA[i][j], B[i][j]​ と呼びます。
次の 2 種類の操作をそれぞれ 縦方向のシフト,横方向のシフト と呼びます。
・j = 1,2,…, W について次の操作を同時に行う。
    A[1][j], A[2][j], …, A[H−1][j], A[H][j]​ を A[2][j], A [3][j], …, A[H][j], A[1][j]に同時に置き換える。
・i = 1, 2,…, H について次の操作を同時に行う。
    A[i][1], A[i][2], …, A[i][W−1], A[i][W]​ を A[i][2], A [i][3], …, A[i][W], A[i][1]​ に同時に置き換える。
次の条件を満たす非負整数の組(s, t)は存在しますか？存在する場合は Yes を、存在しない場合は No を出力してください。
・縦方向のシフトをs 回行い、次に横方向のシフトをt 回行った時、操作後の
A がB と一致する。
ここで、A とB が一致するとは、 1≤i≤H,1≤j≤W を満たす整数の組(i, j) すべてに対してAi,j = B i, j​ が成り立つことを言います。

制約
2　≤　H,W　≤　30
A[i][j], B[i][j]​ は # または .
H, W は整数 */

#include <iostream>
#include <vector>
using namespace std;

// 縦方向のシフトを行う関数
void shift_vertical(vector<string> &grid, int h) {
    string tmp = grid[0];
    for (int i = 0; i < h - 1; i++) {
        grid[i] = grid[i + 1];
    }
    grid[h - 1] = tmp;
}

// 横方向のシフトを行う関数
void shift_horizontal(vector<string> &grid, int h, int w) {
    for (int i = 0; i < h; i++) {
        char tmp = grid[i][0];
        for (int j = 0; j < w - 1; j++) {
            grid[i][j] = grid[i][j + 1];
        }
        grid[i][w - 1] = tmp;
    }
}

// grid が target と一致するかどうかを判定する関数
bool isSame(vector<string> &grid, vector<string> &target, int h, int w) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] != target[i][j]) return false;
        }
    }
    return true;
}

int main() {
    // 入力を受け取る
    int h, w;
    cin >> h >> w;
    vector<string> a(h), b(h);
    for (int i = 0; i < h; ++i) cin >> a[i];
    for (int i = 0; i < h; ++i) cin >> b[i];

    // 縦・横シフトの回数を全探索
    for (int i = 0; i < h; ++i) {
        shift_vertical(a, h);

        for (int j = 0; j < w; ++j) {
            shift_horizontal(a, h, w);
            if (isSame(a, b, h, w)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
