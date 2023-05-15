#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<int> p(n);
    for (int i = 0; i < n; ++i) p[i] = i;

    double sum = 0;
    int cnt = 0;
    do {
        for (int i = 0; i < n-1; ++i) {
            int a = p[i];
            int b = p[i+1];

            double dx = x[a] - x[b];
            double dy = y[a] - y[b];

            sum += sqrt(dx*dx + dy*dy);
        }
        cnt++;
    } while(next_permutation(p.begin(), p.end()));
    double ans = sum / cnt;
    printf("%.10f\n", ans);

    return 0;
}