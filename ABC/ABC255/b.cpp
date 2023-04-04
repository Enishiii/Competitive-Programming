#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<double> r(n);
    for (int i = 0; i < n; ++i) {
        r[i] = 1e18;
        for (int j = 0; j < k; ++j) {
            double dx = x[i] - x[a[j]];
            double dy = y[i] - y[a[j]];
            double dist = sqrt(dx*dx + dy*dy);
            r[i] = min(r[i], dist);
        }
    }

    double ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, r[i]);
    printf("%.10f\n", ans);

    return 0;
}