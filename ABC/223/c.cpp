#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    double t = 0;
    for (int i = 0; i < n; ++i) t += a[i]/b[i];
    t /= 2;

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        double nt = a[i]/b[i];
        if (nt > t) {
            ans += b[i]*t;
            break;
        }
        ans += a[i];
        t -= nt;
    }
    printf("%.10f\n", ans);

    return 0;
}