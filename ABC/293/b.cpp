#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }

    vector<bool> check(n);
    for (int i = 0; i < n; ++i) check[i] = false;

    for (int i = 0; i < n; ++i) {
        if (check[i]) continue;
        else check[a[i]] = true;
    }

    vector<int> ans;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!check[i]) {
            cnt++;
            ans.push_back(i+1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << endl;
    for (auto& x : ans) cout << x << " ";
    cout << endl;

    return 0;
}