#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    string alpha = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << alpha[a[i][j]];
        }
        cout << endl;
    }

    return 0;
}