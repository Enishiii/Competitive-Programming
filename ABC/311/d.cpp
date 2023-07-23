/* 問題文
N×M のグリッドがあり、この上にプレイヤーがいます。
このグリッドの上からi 行目、左からj 列目をマス(i,j) と書きます。
このグリッドの各マスは 氷 か 岩 であり、その情報はN 個の長さM の文字列S1,S2,…,SN として与えられます。
    ・もしSi のj 文字目が . なら、マス(i,j) は 氷 である。
    ・もしSi のj 文字目が # なら、マス(i,j) は 岩 である。
なお、このグリッドの外周 (1 行目、N 行目、1 列目、M 列目の全てのマス ) は 岩 です。
最初、プレイヤーはマス(2,2) の上で停止しています。このマスは 氷 です。
プレイヤーは以下の行動を0 度以上何度でも行うことができます。
    ・まず、プレイヤーは上下左右の移動方向を指定する。
    ・その後、プレイヤーは岩のマスにぶつかるまでその方向に移動する。厳密には以下の通りである。
        ・もし移動方向に隣接するマスが 氷 なら、そのマスに移動し、同じ方向に移動を継続する。
        ・もし移動方向に隣接するマスが 岩 なら、今いるマスに留まり、移動を終了する。
プレイヤーが触れる (通過または上で停止する) ことができる 氷 の数を求めてください。

制約
3≤N,M≤200
Si は # と . からなる長さM の文字列
i=1 またはi=N またはj=1 またはj=M であるとき、マス(i,j) は 岩
マス(2,2) は 氷　*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    vector<int> visited(5*n*m, 0); // n*mのグリッドに対して、上下左右および停止の5つの状態を記録する
    queue<int> q;

    // スタート地点(2, 2）の状態を記録(0-indexedなので、(1, 1))
    // マスの位置を単一のインデックスに変換するため、行と列のインデックスと移動方向を使って、5 * (x * m + y) + d で表現する。
    visited[5*(1*m+1)+4] = 1;
    q.push(5*(1*m+1)+4);

    // BFS
    while(!q.empty()) {
        int curr = q.front(); q.pop();

        // 現在位置の行(x)と列(y)を取得
        int x = (curr / 5) / m;
        int y = (curr / 5) % m;
        int direction = curr % 5; // 現在の移動方向を取得

        if (direction == 4) { // stopped
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int new_direction = i;
                if (grid[nx][ny] == '.') {
                    int new_id = 5 * (nx * m + ny) + new_direction; // 新しい位置とその方向に対応するIDを計算
                    if (visited[new_id] == 0) {
                        visited[new_id] = 1;
                        q.push(new_id);
                    }
                }
            }
        }
        else { // moving
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            int new_direction = direction;
            if (grid[nx][ny] == '.') {
                int new_id = 5 * (nx * m + ny) + new_direction;
                if (visited[new_id] == 0) {
                    visited[new_id] = 1;
                    q.push(new_id);
                }
            }
            else { // hit a rock
                // 岩に当たった後の停止状態のIDを計算
                int new_id = 5 * (x * m + y) + 4;
                if (visited[new_id] == 0) {
                    visited[new_id] = 1;
                    q.push(new_id);
                }
            }
        }
    }

    int ice_count = 0;
    for (int i = 0; i < n*m; ++i) {
        ice_count += max({visited[5*i], visited[5*i+1], visited[5*i+2], visited[5*i+3], visited[5*i+4]}); // 上下左右あるいは停止状態いずれかで訪問したならカウントアップ
    }
    cout << ice_count << endl;

    return 0;
}
