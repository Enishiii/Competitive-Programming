#include <iostream>
using namespace std;

int main() {
    int n, s, k;
    cin >> n >> s >> k;

    int total = 0;
    for (int i = 0; i < n; ++i) {
        int p, q;
        cin >> p >> q;

        total += p * q;
    }

    if (total < s) total += k;

    cout << total << endl;

    return 0;
}
