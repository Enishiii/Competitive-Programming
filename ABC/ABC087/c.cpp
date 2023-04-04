#include <iostream> 
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[2][101];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if (i >= j) cur += a[0][j];
            if (i <= j) cur += a[1][j];
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;

    return 0;
}
