/* 問題文
縦 H マス, 横 W マスのグリッドがあります。上から i 行目、左から j 列目のマスを (i,j) と呼びます。
はじめ、グリッド上には、ある 縦横 2 マス以上 の部分長方形の内部にあるマスにクッキーが 1 枚ずつ置かれていて、それ以外のマスにはクッキーが置かれていません。
形式的に説明すると、以下の条件を全て満たす 4 つの整数の組 (a,b,c,d) がただ 1 つ存在します。
・1≤a<b≤H
・1≤c<d≤W
グリッド上のマスのうち、a≤i≤b,c≤j≤d を満たす全てのマス (i,j) にはクッキーが 1 枚ずつ置かれていて、それ以外のマスにはクッキーが置かれていない。
ところが、すぬけ君がグリッド上のクッキーのどれか 1 枚を取って食べてしまいました。
すぬけ君がクッキーを取ったマスは、クッキーが置かれていない状態に変わります。
すぬけ君がクッキーを食べた後のグリッドの状態が入力として与えられます。
マス (i,j) の状態は文字 Si,j  として与えられて、# はクッキーが置かれているマスを, . はクッキーが置かれていないマスを意味します。
すぬけ君が食べたクッキーが元々置かれていたマスを答えてください。(答えは一意に定まります。)

制約
2≤H,W≤500
S i,j  は # または . */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // グリッドの高さと幅を読み込む
    int height, width;
    cin >> height >> width;

    // グリッドの各セルの状態を保存する配列
    vector<string> grid(height);
    for (int i = 0; i < height; ++i) cin >> grid[i];

    // クッキーが存在する範囲を表す変数
    int min_row = height, max_row = -1;
    int min_column = width, max_column = -1;

    // クッキーが存在する範囲を特定する
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == '#') {
                min_row = min(min_row, i);
                max_row = max(max_row, i);
                min_column = min(min_column, j);
                max_column = max(max_column, j);
            }
        }
    }

    // クッキーが存在する範囲内でクッキーがないマスを探す
    for (int i = min_row; i <= max_row; ++i) {
        for (int j = min_column; j <= max_column; ++j) {
            // 見つけたら、その位置を出力してプログラムを終了
            if (grid[i][j] == '.') {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
