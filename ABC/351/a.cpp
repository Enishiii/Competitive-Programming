#include <iostream>
using namespace std;

int main() {
    int a[9];
    int b[8];

    int a_sum = 0;
    for (int i = 0; i < 9; ++i) {
        cin >> a[i];
        a_sum += a[i];
    }

    int b_sum = 0;
    for (int i = 0; i < 8; ++i) {
        cin >> b[i];
        b_sum += b[i];
    }

    cout << a_sum - b_sum + 1 << endl;

    return 0;
}
