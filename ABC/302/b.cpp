/* 縦h, 横wのマス目に英小文字が書かれている。縦・横・ななめいずれかの方向にs, n, u, k, eが並んでいるのでその場所を見つけ、マス目の位置を出力する問題。

制約
5 ≤ H ≤ 100
5 ≤ W ≤ 100
H,W は整数
Si は英小文字のみからなる長さW の文字列
与えられるマス目の中に条件をみたす場所がただ1 つ存在する */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    string target = "snuke";
    // 縦・横・斜めの８方向へのパターンを保持しておく
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // 制約が小さいのでシンプルに全探索。
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 's') {
                for (int dir = 0; dir < 8; dir++) {
                    bool is_target = true;
                    for (int k = 0; k < 5; k++) {
                        int nx = i + dx[dir] * k;
                        int ny = j + dy[dir] * k;
                        if (nx < 0 || ny < 0 || nx >= H || ny >= W || S[nx][ny] != target[k]) {
                            is_target = false;
                            break;
                        }
                    }
                    if (is_target) {
                        for (int k = 0; k < 5; k++) {
                            int nx = i + dx[dir] * k;
                            int ny = j + dy[dir] * k;
                            cout << nx + 1 << " " << ny + 1 << endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
