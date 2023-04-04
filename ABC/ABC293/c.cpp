#include <iostream>
#include <vector>
#include <set>
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
    set<int> s;
    int ans = 0;

    auto dfs = [&](auto f, int i, int j) -> void {
        if (i >= h || j >= w) return;
        if (s.count(a[i][j])) return;
        if (i == h-1 && j == w-1) {ans++; return;}
        s.insert(a[i][j]);
        f(f, i, j+1);
        f(f, i+1, j);
        s.erase(a[i][j]);
    };
    dfs(dfs, 0, 0);
    cout << ans << endl;

    return 0;
}