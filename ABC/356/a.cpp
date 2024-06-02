#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) a[i] = i;

    int iter = (r - l + 1) / 2;
    for (int i = 0; i < iter; ++i) {
        int left = l + i;
        int right = r - i;

        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i];
        if (i != n) cout << " ";
    }
    cout << endl;

    return 0;
}
