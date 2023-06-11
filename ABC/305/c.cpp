#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    int min_i = h, max_i = -1, min_j = w, max_j = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') {
                min_i = min(min_i, i);
                max_i = max(max_i, i);
                min_j = min(min_j, j);
                max_j = max(max_j, j);
            }
        }
    }

    for (int i = min_i; i <= max_i; ++i) {
        for (int j = min_j; j <= max_j; ++j) {
            if (s[i][j] == '.') {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
