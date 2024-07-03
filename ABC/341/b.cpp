#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n - 1; ++i) {
        int s, t;
        cin >> s >> t;

        a[i + 1] += a[i] / s * t;
    }
    cout << a[n-1] << endl;

    return 0;
}
