#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mp[a]++;
    }
    vector<int> ans;
    for (auto p : mp) ans.push_back(p.second);
    reverse(ans.begin(), ans.end());
    while(ans.size() < n) ans.push_back(0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}