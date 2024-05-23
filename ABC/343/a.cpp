#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int notSum = (a + b == 0) ? 1 : 0;
    cout << notSum << endl;

    return 0;
}
