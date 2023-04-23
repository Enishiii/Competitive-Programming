#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> c(n), r(n);
    bool exist = false;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] == t) exist = true;
    }
    for (int i = 0; i < n; ++i) cin >> r[i];

    int ans = 0, cur = 0;
    if (exist) {
        for (int i = 0; i < n; ++i) {
            if (c[i] != t) continue;
            if (cur < r[i]) {
                cur = r[i];
                ans = i+1;
            }
        }
    } else {
        for (int i = 0; i < n; ++i){
            int color = c[0];
            if (c[i] != color) continue;
            if (cur < r[i]) {
                cur = r[i];
                ans = i+1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
