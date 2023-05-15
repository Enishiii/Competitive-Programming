#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c(n+m);
    for (int i = 0; i < n+m; ++i) {
        cin >> c[i].first;
        c[i].second = i;
    }
    inplace_merge(c.begin(), c.begin()+n, c.end());

    vector<int> ans(n+m);
    for (int i = 0; i < n+m; ++i) {
        ans[c[i].second] = i+1;
    }
    for (int i = 0; i < n+m; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}