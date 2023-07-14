#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<double> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    vector<double> e(n);
    for (int i = 0; i < n; ++i) e[i] = (p[i]+1) / 2;

    vector<double> s(n+1, 0);
    for (int i = 0; i < n; ++i) s[i+1] = s[i] + e[i];

    double maxE = 0;
    for (int i = 0; i <= n-k; ++i) maxE = max(maxE, s[i+k] - s[i]);

    cout << setprecision(10) << maxE << endl;

    return 0;
}
