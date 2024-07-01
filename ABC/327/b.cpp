#include <iostream>
using namespace std;

int main() {
    long long targetValue;
    cin >> targetValue;

    for (int base = 1; base <= 15; ++base) {
        long long currentValue = 1;
        for (int i = 0; i < base; ++i) currentValue *= base;
        if (currentValue == targetValue) {
            cout << base << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
