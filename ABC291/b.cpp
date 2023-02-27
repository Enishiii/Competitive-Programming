#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(5*n);
    int sum = 0;
    for (int i = 0; i < 5*n; ++i) {
        cin >>x[i];
        sum += x[i];
    }

    sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
        int mx = 0;
        for (int j = 0; j < n; ++j) {
            if (mx < x[i]) mx = x[i];
        }
        sum -= mx;
    }

    sort(x.rbegin(), x.rend());
    for (int i = 0; i < n; ++i) {
        int mx2 = 0;
        for (int j = 0; j < n; ++j) {
            if (mx2 < x[i]) mx2 = x[i];
        }
        sum -= mx2;
    }

    double ans = (double)sum / (n*3);
    printf("%.10f\n", ans);

    return 0;
}