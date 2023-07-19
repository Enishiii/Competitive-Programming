#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void dfs(int x, int y, vector<int> edges[], bool visited[], bool& reached, deque<int>& path) {
    if (!reached) path.push_back(x);

    if (x == y) reached = true;

    visited[x] = true;

    int size = edges[x].size();
    for (int i = 0; i < size; ++i) {
        if (!visited[edges[x][i]]) {
            dfs(edges[x][i], y, edges, visited, reached, path);
        }
    }

    if (!reached) path.pop_back();
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> edges[n+1];
    bool visited[n+1];
    bool reached = false;
    deque<int> path;

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    fill(visited, visited + n + 1, false);

    dfs(x, y, edges, visited, reached, path);

    while(!path.empty()) {
        cout << path.front();
        path.pop_front();
        cout << (path.empty() ? "\n" : " ");
    }

    return 0;
}
