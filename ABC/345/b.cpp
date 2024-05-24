#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;

    if (x % 10 == 0) {
        cout << x / 10 << endl;
        return 0;
    }

    if (x >= 0) {
        cout << (x + 10 - 1) / 10 << endl;
    } else {
        cout << x / 10 << endl;
    }

    return 0;
}
