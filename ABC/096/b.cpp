#include <iostream>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    cout << a + b + c + max(a, max(b, c)) * ((1 << k) - 1) << endl;

    return 0;
}
