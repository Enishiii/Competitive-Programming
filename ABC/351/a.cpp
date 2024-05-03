#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 0;

    int inputNum;
    for (int i = 0; i < 9; ++i) {
        cin >> inputNum;
        a += inputNum;
    }

    for (int i = 0; i < 8; ++i) {
        cin >> inputNum;
        b += inputNum;
    }

    cout << a - b + 1 << endl;

    return 0;
}
