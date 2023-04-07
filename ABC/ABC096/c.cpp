#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    for (int i = 0; i < h; ++i) cin >> c[i];

    vector ok(h, vector<bool>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (c[i][j] != '#') continue;
            if (i-1 >= 0 && c[i-1][j] == '#') ok[i][j] = true;
            if (j-1 >= 0 && c[i][j-1] == '#') ok[i][j] = true;
            if (i+1 < h && c[i+1][j] == '#') ok[i][j] = true;
            if (j+1 < w && c[i][j+1] == '#') ok[i][j] = true;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (c[i][j] == '#' && !ok[i][j]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}
