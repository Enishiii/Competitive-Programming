#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans = "1";
    for (int i = 0; i < n; ++i) {
        ans += "01";
    }
    cout << ans << endl;

    return 0;
}
