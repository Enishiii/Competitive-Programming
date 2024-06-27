#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ans;
    for (int i = 0; i < n; ++i) ans += to_string(n);
    cout << ans << endl;

    return 0;
}
