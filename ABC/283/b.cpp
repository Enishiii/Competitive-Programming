#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int t, k;
        cin >> t >> k;

        if (t == 1) {
            int x;
            cin >> x;
            a[k-1] = x;
        } else if (t == 2) {
            cout << a[k-1] << endl;
        }
    }

    return 0;
}
