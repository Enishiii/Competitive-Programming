#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long h;
    cin >> h;

    int plant = 0;
    for (int i = 0; ; ++i) {
        plant += pow(2, i);

        if (h < plant) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
