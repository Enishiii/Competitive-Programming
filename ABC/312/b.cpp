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
    "?????.###"};

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
