#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u-1].push_back(v);
        a[v-1].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
        cout << size(a[i]);
        for (auto x : a[i]) cout << ' ' << x;
        cout << endl;
    }

    return 0;
}
