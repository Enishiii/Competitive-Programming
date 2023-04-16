// a, bの最大公約数を求める問題。

#include <iostream>
using namespace std;

int GCD(int a, int b) {
    while(a > 0 && b > 0) {
        if (a >= b) a %= b;
        else b %= a;
    }

    if (a) return a;
    else return b;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << endl;

    return 0;
}
