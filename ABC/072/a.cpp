#include <iostream>
using namespace std;

int main() {
    int x, t;
    cin >> x >> t;

    if (x <= t) {
        cout << 0 << endl;
    } else {
        cout << x - t << endl;
    }

    return 0;
}
