#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> c(n+m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[i] = a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        c[n+i] = b[i];
    }

    sort(c.begin(), c.end());
    sort(a.begin(), a.end());

    for (int i = 0; i < n+m-1; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (c[i] == a[j] && c[i+1] == a[j+1]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
