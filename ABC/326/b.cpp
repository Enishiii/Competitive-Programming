#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(true) {
        int ichi = (n % 100) % 10;
        int hyakutojuu = (n / 100) * (n % 100 / 10);

        if (ichi == hyakutojuu) {
            cout << n << endl;
            return 0;
        }
        n++;
    }

    return 0;
}
