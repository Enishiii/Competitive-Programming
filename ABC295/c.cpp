#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] == 2) {
            ans++;
            mp[a[i]] = 0;
        }
    }
    cout << ans << endl;

    return 0;
}