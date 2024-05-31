#include <iostream>
#include <vector>
using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int turnRight(int dir) {
    return (dir + 1) % 4;
}

int turnLeft(int dir) {
    return (dir + 3) % 4;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<bool>> grid(h, vector<bool>(w, false));

    int row = 0;
    int col = 0;
    int dir = UP;

    for (int i = 0; i < n; ++i) {
        bool isWhite = !grid[row][col];

        grid[row][col] = !grid[row][col];

        if (isWhite) {
            dir = turnRight(dir);
        } else {
            dir = turnLeft(dir);
        }

        switch(dir) {
            case UP:
                row = (row - 1 + h) % h;
                break;
            case RIGHT:
                col = (col + 1) % w;
                break;
            case DOWN:
                row = (row + 1) % h;
                break;
            case LEFT:
                col = (col - 1 + w) % w;
                break;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << (grid[i][j] ? '#' : '.');
        }
        cout << endl;
    }

    return 0;
}
