#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> c(n), d(m+1);
    vector<int> p(m+1);
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 1; i <= m; ++i) cin >> d[i];
    for (int i = 0; i <= m; ++i) cin >> p[i];

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        bool matched = false;
        for (int j = 1; j <= m; ++j) {
            if (c[i] == d[j]) {
                sum += p[j];
                matched = true;
            }
        }
        if (!matched) sum += p[0];
    }
    cout << sum << endl;

    return 0;
}
