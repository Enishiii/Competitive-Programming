#include <iostream>
#include <vector>
using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int turnRight(int direction) {
    return (direction + 1) % 4;
}

int turnLeft(int direction) {
    return (direction + 3) % 4;
}

int main() {
    int height, width, numOperations;
    cin >> height >> width >> numOperations;

    vector<vector<bool>> grid(height, vector<bool>(width, false));

    int currentRow = 0;
    int currentCol = 0;
    int direction = UP;

    for (int i = 0; i < numOperations; ++i) {
        bool isWhite = !grid[currentRow][currentCol];

        grid[currentRow][currentCol] = !grid[currentRow][currentCol];

        if (isWhite) {
            direction = turnRight(direction);
        } else {
            direction = turnLeft(direction);
        }

        switch(direction) {
            case UP:
                currentRow = (currentRow - 1 + height) % height;
                break;
            case RIGHT:
                currentCol = (currentCol + 1) % width;
                break;
            case DOWN:
                currentRow = (currentRow + 1) % height;
                break;
            case LEFT:
                currentCol = (currentCol - 1 + width) % width;
                break;
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << (grid[i][j] ? '#' : '.');
        }
        cout << endl;
    }

    return 0;
}
