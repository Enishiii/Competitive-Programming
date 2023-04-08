#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    while(1) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 != 0) ok = false;
        }
        if (ok) {
            ans++;
            for (int i = 0; i < n; ++i) a[i] /= 2;
        } else break;
    }
    cout << ans << endl;

    return 0;
}
