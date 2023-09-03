#include <iostream>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;
    int day = 1, cycle = 0;
    while(day <= n) {
        if (m + p * cycle == day) {
            ans++;
            cycle++;
        }

        day++;
    }
    cout << ans << endl;

    return 0;
}
