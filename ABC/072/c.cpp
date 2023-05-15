#include <iostream>
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

    int ans = 0;
    for (int i = 0; i <= 100000; ++i) {
        int cur = mp[i-1] + mp[i] + mp[i+1];
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}
