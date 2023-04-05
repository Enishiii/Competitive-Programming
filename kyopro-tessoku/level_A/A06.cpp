#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a[100009], s[100009];
    int q, l[100009], r[100009];

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= q; ++i) cin >> l[i] >> r[i];

    s[0] = 0;
    for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];

    for (int i = 1; i <= q; ++i) {
        cout << s[r[i]] - s[l[i]-1] << endl;
    }

        return 0;
}
