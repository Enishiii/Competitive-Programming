#include <iostream>
using namespace std;

void printTetrahedralNumbers(int maxNumber) {
    for (int x = 0; x <= maxNumber; ++x) {
        for (int y = 0; y <= maxNumber; ++y) {
            for (int z = 0; z <= maxNumber; ++z) {
                if ((x + y + z) > maxNumber) continue;

                cout << x << " " << y << " " << z << endl;
            }
        }
    }
}

int main() {
    int maxNumber;
    cin >> maxNumber;

    printTetrahedralNumbers(maxNumber);

    return 0;
}
