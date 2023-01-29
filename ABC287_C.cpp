#include <iostream>
#include <vector>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

bool solve() {
    int n, m;
    cin >> n >> m;
    vector<int> degree(n);
    dsu uf(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        degree[u]++;
        degree[v]++;
        uf.merge(u, v);
    }

    int one = 0;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 0 || degree[i] > 2) return false;
        if (degree[i] == 1) one++;
    }
    if (one != 2) return false;

    if (uf.size(0) != n) return false;

    return true;
}

int main() {
    if (solve()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
