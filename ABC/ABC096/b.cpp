#include <iostream>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if (a >= b && a >= c) {
        for (int i = 0; i < k; ++i) a *= 2;
    } else if (b >= a && b >= c) {
        for (int i = 0; i < k; ++i) b *= 2;
    } else if (c >= a && c >= b) {
        for (int i = 0; i < k; ++i) c *= 2;
    }

    cout << a+b+c << endl;

    return 0;
}
