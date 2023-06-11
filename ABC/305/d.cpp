#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> fa(n);
    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0) fa[i] = fa[i-1] + a[i] - a[i-1];
        else fa[i] = fa[i-1];
    }

    int q;
    cin >> q;

    auto f{[&a, &fa](auto x) -> unsigned {
        const auto j = upper_bound(begin(a)+1, end(a), x) - begin(a) - 1;
        return fa[j] + (fa[j+1] - fa[j]) / (a[j+1] - a[j]) * (x - a[j]);
    }};

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << f(r) - f(l) << "\n";
    }

    return 0;
}
