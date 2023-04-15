#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<int> x(q);
    int n = 300000;
    vector<bool> deleted(n);
    for (int i = 0; i < q; ++i) cin >> x[i];

    for (int i = 2; i * i <= n; ++i) {
        if (deleted[i]) continue;
        for (int j = i * 2; j <= n; j += i) {
            deleted[j] = true;
        }
    }

    for (int i = 0; i < q; ++i) {
        if (deleted[x[i]] == false) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
