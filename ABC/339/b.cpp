#include <iostream>
#include <vector>
using namespace std;

class Grid {
public:
    Grid(int height, int width): height_(height), width_(width), isBlack_(height, vector<bool>(width, false)), row_(0), col_(0), direction_(UP) {}

    void performOperations(int numOperations) {
        for (int i = 0; i < numOperations; ++i) {
            moveAndPaint();
        }
    }

    void print() const {
        for (int i = 0; i < height_; ++i) {
            for (int j = 0; j < width_; ++j) {
                cout << (isBlack_[i][j] ? BLACK : WHITE);
            }
            cout << endl;
        }
    }

private:
    int height_;
    int width_;
    vector<vector<bool>> isBlack_;
    int row_;
    int col_;
    int direction_;

    static const char WHITE = '.';
    static const char BLACK = '#';

    static const int UP = 0;
    static const int RIGHT = 1;
    static const int DOWN = 2;
    static const int LEFT = 3;

    int turnRight(int direction) {
        return (direction + 1) % 4;
    }

    int turnLeft(int direction) {
        return (direction + 3) % 4;
    }

    void moveForward() {
        switch(direction_) {
            case UP:
                row_ = (row_ - 1 + height_) % height_;
                break;
            case RIGHT:
                col_ = (col_ + 1) % width_;
                break;
            case DOWN:
                row_ = (row_ + 1) % height_;
                break;
            case LEFT:
                col_ = (col_ - 1 + width_) % width_;
                break;
        }
    }

    void paintSquare() {
        isBlack_[row_][col_] = !isBlack_[row_][col_];
    }

    void moveAndPaint() {
        bool isWhite = !isBlack_[row_][col_];

        paintSquare();

        if (isWhite) {
            direction_ = turnRight(direction_);
        } else {
            direction_ = turnLeft(direction_);
        }

        moveForward();
    }
};

int main() {
    int height, width, numOperations;
    cin >> height >> width >> numOperations;

    Grid grid(height, width);

    grid.performOperations(numOperations);

    grid.print();

    return 0;
}
