#include <iostream>
#include <vector>
using namespace std;

int n, m;

void output(vector<int> a) {
    for (int i = 0; i < n; ++i) {
        printf("%d%c", a[i], i==n-1?'\n':' ');
    }
}

void dfs(vector<int> a) {
    if (a.size() == n) {
        output(a);
        return;
    }
    int sx = 1;
    if (a.size() > 0) {
        sx = a.back()+1;
    }
    a.push_back(sx);
    while(a.back() <= m) {
        dfs(a);
        a.back()++;
    }
}


int main() {
    cin >> n >> m;
    dfs({});

    return 0;
}
