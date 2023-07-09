#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<string> b = a;

    for (int j = 0; j < n-1; ++j) b[0][j+1] = a[0][j];
    for (int i = 0; i < n-1; ++i) b[i+1][n-1] = a[i][n-1];
    for (int j = n-1; j > 0; --j) b[n-1][j-1] = a[n-1][j];
    for (int i = n-1; i > 0; --i) b[i-1][0] = a[i][0];

    b[0][0] = a[1][0];
    b[0][n-1] = a[0][n-2];
    b[n-1][n-1] = a[n-2][n-1];
    b[n-1][0] = a[n-1][1];

    for (int i = 0; i < n; ++i) cout << b[i] << endl;

    return 0;
}
