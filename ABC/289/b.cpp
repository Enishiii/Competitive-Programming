#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> re(n+1);
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        re[a] = true;
    }

    vector<int> b;
    for (int i = 0; i < n+1; ++i) {
        if (!re[i]) b.push_back(i);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = i+1;
    for (int i = 0; i < b.size()-1; ++i) {
        reverse(ans.begin()+b[i], ans.begin()+b[i+1]);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}