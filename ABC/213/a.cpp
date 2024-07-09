#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    for (int c = 0; c <= 255; ++c) {
        // aとcの排他的論理和(xor)がbと等しければ、cを出力
        if ((a^c) == b) {
            cout << c << endl;
            return 0;
        }
    }

    return 0;
}
