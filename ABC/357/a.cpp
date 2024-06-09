#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int count = 0;
    for (int i = 0; i < n; ++i) {
        m -= h[i];

        if (m < 0) break;
        count++;
    }
    cout << count << endl;

    return 0;
}
