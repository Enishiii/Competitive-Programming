#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        cout << clamp(a[i], l, r) << " \n"[i == n - 1];
    }

    return 0;
}
