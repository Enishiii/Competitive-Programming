#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t >> l[i] >> r[i];
        l[i] *= 2;
        r[i] *= 2;
        if (t >= 3) l[i]++;
        if (t % 2 == 0) r[i]--;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (r[j] < l[i]) continue;
            if (r[i] < l[j]) continue;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
