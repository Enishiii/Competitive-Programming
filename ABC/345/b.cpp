#include <iostream>
using namespace std;

const int ADJUSTMENT = 9;
const int DIVISOR = 10;

long long adjustInput(long long inputNumber) {
    return inputNumber + ADJUSTMENT;
}

long long calcRoundedResult(long long adjusted) {
    return adjusted / DIVISOR;
}

long long adjustForNegative(long long adjusted, long long divided) {
    if (adjusted <= 0 && adjusted % DIVISOR != 0) {
        divided--;
    }
    return divided;
}

int main() {
    long long inputNumber;
    cin >> inputNumber;

    long long adjusted = adjustInput(inputNumber);
    long long divided = calcRoundedResult(adjusted);
    long long result = adjustForNegative(adjusted, divided);

    cout << result << endl;

    return 0;
}
