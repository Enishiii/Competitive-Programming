#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = -1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] > mx) {
            mx = a[i];
        }
    }

    int secondMx = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mx) continue;

        if (secondMx < a[i]) secondMx = a[i];
    }

    cout << secondMx << endl;

    return 0;
}
