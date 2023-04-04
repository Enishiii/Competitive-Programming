#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> b(r);
    for (int i = 0; i < r; ++i) cin >> b[i];

    vector blasted(r, vector<bool>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (!isdigit(b[i][j])) continue;
            int impact = b[i][j]-'0';
            for (int k = 0; k < r; ++k) {
                for (int l = 0; l < c; ++l) {
                    int dist = abs(i-k) + abs(j-l);
                    if (dist <= impact) blasted[k][l] = true;
                }
            }
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (blasted[i][j]) b[i][j] = '.';
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << b[i][j];
        }
        cout << endl;
    }

    return 0;
}