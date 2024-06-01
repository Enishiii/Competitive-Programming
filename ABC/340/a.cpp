#include <iostream>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;

    for (int i = a; i <= b; i += d) {
        cout << i;
        if (i != b) cout << " ";
    }
    cout << endl;

    return 0;
}
