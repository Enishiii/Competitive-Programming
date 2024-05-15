#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int cntStart = 0;
    int remainedSeats = k;

    for (int index = 0; index < n; ++index) {
        if (a[index] > remainedSeats) {
            cntStart++;
            remainedSeats = k;
            index--;
        } else {
            remainedSeats -= a[index];
        }
    }
    cout << cntStart+1 << endl;

    return 0;
}
