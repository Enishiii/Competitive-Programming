#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> t[i];

    for (int i = 0; i < n*2; ++i) {
        t[(i+1)%n] = min(t[(i+1)%n], s[i%n]+t[i%n]);
    }
    for (int i = 0; i < n; ++i) {
        cout << t[i] << endl;
    }

    return 0;
}