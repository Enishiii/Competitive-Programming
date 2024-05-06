#include <iostream>
using namespace std;

int readInputCount() {
    int inputCount;
    cin >> inputCount;
    return inputCount;
}

int calculateTotal(int numCount) {
    int total = 0;
    int input;
    for (int i = 0; i < numCount-1; i++) {
        cin >> input;
        total += input;
    }
    return total;
}

int main() {
    int inputCount = readInputCount();

    int total = calculateTotal(inputCount);

    cout << -total << endl;

    return 0;
}
