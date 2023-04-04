#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) cnt++;
    }
    long long ans = cnt*(cnt-1)/2;

    for (int i = 0; i < n; ++i) {
        if (a[i] <= i) continue;
        if (a[a[i]] == i) ans++;
    }
    cout << ans << endl;

    return 0;
}