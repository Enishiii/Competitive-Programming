#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> readMatrix(int size) {
    vector<vector<int>> matrix(size, vector<int>(size));

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            cin >> matrix[row][col];
        }
    }

    return matrix;
}

void printOnesIndices(const vector<vector<int>>& matrix) {
    int size = matrix.size();

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            if (matrix[row][col] == 1) {
                cout << col + 1;
                if (col != size - 1) cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int matrixSize;
    cin >> matrixSize;

    vector<vector<int>> matrix = readMatrix(matrixSize);

    printOnesIndices(matrix);

    return 0;
}
