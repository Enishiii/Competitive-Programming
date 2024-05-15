#include <iostream>
using namespace std;

int main() {
    int groupNum, maxSeats;
    cin >> groupNum >> maxSeats;

    int startCount = 0;
    int remainedSeats = maxSeats;

    for (int i = 0; i < groupNum; ++i) {
        int occupiedSeats;
        cin >> occupiedSeats;

        if (occupiedSeats > remainedSeats) {
            startCount++;
            remainedSeats = maxSeats;
        }
        remainedSeats -= occupiedSeats;
    }

    cout << startCount+1 << endl;

    return 0;
}
