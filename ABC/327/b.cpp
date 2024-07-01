#include <iostream>
using namespace std;

bool isMatchingBase(long long targetValue, int base) {
    long long currentValue = 1;
    for (int i = 0; i < base; ++i) {
        currentValue *= base;
    }
    return currentValue == targetValue;
}

int main() {
    long long targetValue;
    cin >> targetValue;

    for (int base = 1; base <= 15; ++base) {
        if (isMatchingBase(targetValue, base)) {
            cout << base << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
