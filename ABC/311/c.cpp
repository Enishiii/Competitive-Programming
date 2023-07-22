#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2 * 1e5 + 5;

vector<int> edge[MAXN], path;
int visited[MAXN];
int cycle_start, cycle_end;

bool dfs(int v) {
    visited[v] = 1;
    path.push_back(v);

    for (auto u : edge[v]) {
        if (visited[u] == 0) {
            if (dfs(u)) return true;
        } else {
            cycle_start = u;
            cycle_end = v;
            return true;
        }
    }

    path.pop_back();
    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        edge[i].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0 && dfs(i)) break;
    }

    auto it_start = find(path.begin(), path.end(), cycle_start);
    auto it_end = find(path.begin(), path.end(), cycle_end);
    vector<int> cycle(it_start, it_end+1);

    cout << cycle.size() << endl;
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
