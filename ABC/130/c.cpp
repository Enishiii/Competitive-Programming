#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long w, h, x, y;
    cin >> w >> h >> x >> y;

    double half = w * h / 2.0;

    int multi = 0;
    if (x * 2 == w && y * 2 == h) multi = 1;

    cout << fixed << setprecision(10) << half << " " << multi << "\n";

    return 0;
}
