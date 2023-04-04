#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') ans = i+1;
    }
    cout << ans << endl;

    return 0;
}
