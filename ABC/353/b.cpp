#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int startCount = 0;
    int remainedSeats = k;

    for (int i = 0; i < n; ++i) {
        int occupiedSeats;
        cin >> occupiedSeats;

        if (occupiedSeats > remainedSeats) {
            startCount++;
            remainedSeats = k;
        }
        remainedSeats -= occupiedSeats;
    }

    cout << startCount+1 << endl;

    return 0;
}
