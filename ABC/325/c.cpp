// 問題文
// H 行 W 列のマス目の上に 0 個以上のセンサが配置されています。上から i 行目、左から j 列目のマス目を (i,j) と表記します。
// センサが配置されているマス目の情報は長さ W の文字列 S1,S2,…,SH によって与えられ、Si のj 文字目が # のとき、またそのときに限り (i,j) にセンサが配置されています。
// このセンサは上下左右斜めに隣接しているマス目に存在する他のセンサと連動し、一つのセンサとして動作します。 ただし、マス目 (x,y) と(x′,y′) が上下左右斜めに隣接しているとは、max(∣x−x′∣,∣y−y′∣)=1 であることを指します。
// また、センサ A とセンサ B が連動し、センサ A とセンサ C が連動しているとき、センサ B とセンサ C も連動することに注意してください。
// 連動するセンサを一つのセンサと見なしたとき、このマス目の上にあるセンサの個数を求めてください。

// 制約
// 1≤H,W≤1000
// H,W は整数
// Si は各文字が # または . である長さ W の文字列

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class SensorField {
private:
    const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

    vector<vector<char>> s;
    vector<vector<bool>> used;

    void bfs(int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        used[x][y] = true;

        while(!que.empty()) {
            auto [currentX, currentY] = que.front();
            que.pop();

            for (int d = 0; d < 8; ++d) {
                int nx = currentX + dx[d];
                int ny = currentY + dy[d];

                if (nx < 0 || nx >= s.size() || ny < 0 || ny >= s[0].size()) continue;
                if (s[nx][ny] == '.' || used[nx][ny]) continue;

                used[nx][ny] = true;
                que.push({nx, ny});
            }
        }
    }

public:
    SensorField(int h, int w) : s(h, vector<char>(w)), used(h, vector<bool>(w)) {}

    void setInputField(const vector<vector<char>>& field) {
        s = field;
    }

    int countGroups() {
        int groupCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s[0].size(); ++j) {
                if (s[i][j] == '#' && !used[i][j]) {
                    bfs(i, j);
                    groupCount++;
                }
            }
        }
        return groupCount;
    }
};

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> fieldData(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> fieldData[i][j];
        }
    }

    SensorField field(h, w);
    field.setInputField(fieldData);
    cout << field.countGroups() << endl;

    return 0;
}
