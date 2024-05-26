#include <iostream>
using namespace std;

int main() {
    int input1, input2;
    cin >> input1 >> input2;

    if (input1 == input2) {
        cout << -1 << endl;
    } else {
        cout << 6 - input1 - input2 << endl;
    }

    return 0;
}
