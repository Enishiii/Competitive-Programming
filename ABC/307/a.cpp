#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < 7; ++j) {
            int a;
            cin >> a;
            ans += a;
        }
        if (i) cout << " ";
        cout << ans;
    }
    cout << endl;

    return 0;
}
