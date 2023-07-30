/* 問題文
高橋君は2 次元コード TaK Code を考案しました。以下の条件を全て満たすものが TaK Code です。
    ・縦9 マス 横9 マスの領域である
    ・左上及び右下の縦3 マス 横3 マスの領域に含まれる計18 マスは全て黒である
    ・左上及び右下の縦3 マス 横3 マスの領域に八方位で隣接する計14 マスは全て白である
TaK Code を回転させることはできません。
縦N マス、横M マスのグリッドがあります。 グリッドの状態はN 個の長さ
M の文字列S1,…,SN で与えられ、上からi 行目左からj 列目のマスは
Si のj 文字目が # のとき黒、. のとき白です。
グリッドに完全に含まれる縦9 マス横9 マスの領域で、TaK Code の条件を満たす箇所を全て求めてください。

制約
9≤N,M≤100
N,M は整数である
Si は . および # のみからなる長さM の文字列である */

#include <iostream>
#include <vector>
    using namespace std;

// TaK Codeのパターンを定義
vector<string> pattern = {
    "###.?????",
    "###.?????",
    "###.?????",
    "....?????",
    "?????????",
    "?????....",
    "?????.###",
    "?????.###",
    "?????.###"
};

bool check(int x, int y, const vector<string> &grid) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (pattern[i][j] != '?' && grid[x + i][y + j] != pattern[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    // グリッドの各位置でTaK Codeのパターンが一致するか調べる
    for (int i = 0; i <= N - 9; ++i) {
        for (int j = 0; j <= M - 9; ++j) {
            if (check(i, j, grid)) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }

    return 0;
}
