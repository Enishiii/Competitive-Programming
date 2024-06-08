#include <iostream>
using namespace std;

void printCombinations(int n) {
    for (int x = 0; x <= n; ++x) {
        for (int y = 0; y <= n; ++y) {
            for (int z = 0; z <= n; ++z) {
                if ((x + y + z) > n) continue;

                cout << x << " " << y << " " << z << endl;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    printCombinations(n);

    return 0;
}
