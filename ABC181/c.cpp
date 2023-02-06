#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < j; ++k) {
                int a = x[j] - x[i], b = y[j] - y[i];
                int c = x[k] - x[i], d = y[k] - y[i];
                if (a*d == b*c) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
