#include <iostream>
using namespace std;

int sumInputs(int count) {
    int sum = 0;

    int inputNum;
    for (int i = 0; i < count; ++i) {
        cin >> inputNum;
        sum += inputNum;
    }

    return sum;
}

int main() {
    int a = sumInputs(9);
    int b = sumInputs(8);

    cout << a - b + 1 << endl;

    return 0;
}
