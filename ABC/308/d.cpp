#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int x, int y, int t, int h, int w, vector<string> grid, string target) {
    return x >= 0 && y >= 0 && x < h && y < w && grid[x][y] == target[t % 5];
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) cin >> grid[i];

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    visited[0][0] = true;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    string target = "snuke";

    while(!q.empty()) {
        int t = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == h-1 && y == w-1) {
            cout << "Yes" << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, t+1, h, w, grid, target) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({t+1, {nx, ny}});
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
